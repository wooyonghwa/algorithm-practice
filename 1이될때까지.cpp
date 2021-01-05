#include <iostream>
#include <vector>
using namespace std;
int main(void) {

	int N = 27, K = 3;
	
	int cnt = 0;

	while (N != 1) {
		if (N % K == 0) {
			N = N / K;
		}
		else {
			N = N - 1;
		}
		cnt++;
	}
	
	cout << cnt << '\n';

}
