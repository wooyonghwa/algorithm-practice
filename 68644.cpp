#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves);
int main(void) {
	vector<vector<int>> board = { {0,0,0,0,0} ,{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };
	cout<<solution(board,moves);
	return 0;
}
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s[31];
	//�ٱ���
	stack<int> result;
	for (int i = 0; i < board.size(); i++) {
		for (int j = board[i].size() - 1; j >= 0; j--) {
			//0�� �ƴ� ��쿡�� �־���	
			if (board[j][i] != 0) {
				s[i].push(board[j][i]);
			}
		}
	}

	for (int i = 0; i < moves.size(); i++) {
		//�� �� stack�� �������� �ϸ� �׳� �־���
		if (result.empty()) {
			//������ ������ ���� ��������� �ȵǱ� ������ üũ����
			if (!s[moves[i]-1].empty()) {
				result.push(s[moves[i]-1].top());
				s[moves[i]-1].pop();
			}
		}
		else {
			//������ ���� ���� �ʾҴٸ�
			if (!s[moves[i]-1].empty()) {
				//������ ���� top�� �ٱ����� top�� ������
				if (result.top() == s[moves[i]-1].top()) {
					//�ٱ��Ͽ��� ���ְ�
					result.pop();
					s[moves[i] - 1].pop();
					//count ����
					answer++;
				}
				else {
					result.push(s[moves[i]-1].top());
					s[moves[i]-1].pop();
				}
			}
		}
	}
	return answer*2;
}