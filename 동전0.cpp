#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int N, K;
	int num;
	int result = 0;
	cin >> N >> K;
	
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	for (int i = N; i >= 1; i--) {
		if (K == 0) break;
		if (K / arr[i - 1] > 0) {
			result += K / arr[i - 1];
			K %= arr[i - 1];
		}
	}
	cout << result;
	return 0;
}