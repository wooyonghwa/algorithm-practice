#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve);
int arr[31];
int main(void) {

	vector<int> lost = {4, 5 };
	vector<int> reserve = { 3,4 };
	int n = 5;
	cout << solution(n, lost, reserve);

	return 0;
}
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	for (int i = 0; i < lost.size(); i++) {
		//�Ҿ���� �� -1 ����(���� ü���� ������ ����� ���� �� �� �־)
		arr[lost[i]] -= 1;
	}
	for (int i = 0; i < reserve.size(); i++) {
		//���°� 1 �׿ܴ� 0
		arr[reserve[i]] += 1;
	}

	//�Ҿ���� �͵� �߿���
	for (int i = 0; i < lost.size(); i++) {
		//���� �ְ� �������� ������ �׸��� �ڱ� �ڽ��� ���� ���Ѱſ�����
		if (lost[i] > 1 && arr[lost[i] - 1] == 1 && arr[lost[i]] == -1) {
			//���� �ָ� ��� �ڱⰡ �ö�
			arr[lost[i] - 1] -=1;
			arr[lost[i]]+=1;
		}
		//���ʾִ� ������ ���� ������ �ְ� ������ ������
		else if (lost[i] < n && arr[lost[i] + 1] == 1 && arr[lost[i]] == -1) {
			arr[lost[i] + 1] -=1;
			arr[lost[i]]+=1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] >= 0) {
			answer++;
		}
	}
	return answer;
}