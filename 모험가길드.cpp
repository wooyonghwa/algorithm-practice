#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {

	int N = 5;

	vector<int> arr = { 2,3,1,2,2};
	//����
	sort(arr.begin(), arr.end());

	//������ ���� �� �ִ� �׷� ���
	int resultGroupCnt = 0;
	//�׷� �� ī��Ʈ
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt++;
		//���� �׷� ī��Ʈ�� �ּ� ������ ����� ä������
		if (cnt >= arr[i]) {
			resultGroupCnt++; //�׷� �� ����
			cnt = 0;
		}

	}
	cout << resultGroupCnt << '\n';

}
