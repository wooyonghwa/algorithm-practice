#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	//거슬러 줘야할 돈
	int N = 900;
	//최소 동전 개수
	int minimum = 0;
	//거슬러 줄 수 있는 동전
	vector<int> leftMoney = { 500,100,50,10 };

	for (int i = 0; i < leftMoney.size(); i++) {
		if (N / leftMoney[i]) {
			minimum += N / leftMoney[i];
			N = N % leftMoney[i];
		}
	}
	cout << minimum;

}
