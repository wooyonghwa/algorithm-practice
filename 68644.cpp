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
	//바구니
	stack<int> result;
	for (int i = 0; i < board.size(); i++) {
		for (int j = board[i].size() - 1; j >= 0; j--) {
			//0이 아닌 경우에만 넣어줌	
			if (board[j][i] != 0) {
				s[i].push(board[j][i]);
			}
		}
	}

	for (int i = 0; i < moves.size(); i++) {
		//텅 빈 stack에 넣으려고 하면 그냥 넣어줌
		if (result.empty()) {
			//하지만 빼려는 곳도 비어있으면 안되기 때문에 체크해줌
			if (!s[moves[i]-1].empty()) {
				result.push(s[moves[i]-1].top());
				s[moves[i]-1].pop();
			}
		}
		else {
			//빼려는 곳이 비지 않았다면
			if (!s[moves[i]-1].empty()) {
				//빼려는 곳의 top과 바구니의 top이 같으면
				if (result.top() == s[moves[i]-1].top()) {
					//바구니에서 빼주고
					result.pop();
					s[moves[i] - 1].pop();
					//count 증가
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