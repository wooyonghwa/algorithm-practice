#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	//�Ž��� ����� ��
	int N = 900;
	//�ּ� ���� ����
	int minimum = 0;
	//�Ž��� �� �� �ִ� ����
	vector<int> leftMoney = { 500,100,50,10 };

	for (int i = 0; i < leftMoney.size(); i++) {
		if (N / leftMoney[i]) {
			minimum += N / leftMoney[i];
			N = N % leftMoney[i];
		}
	}
	cout << minimum;

}
