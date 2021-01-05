#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {

	int N = 2, M = 4;
	vector<vector<int>> arr = { {7,3,1,8},{3,3,3,4} };
	
	int max = 0;

	for (int i = 0; i < N; i++) {
		sort(arr[i].begin(),arr[i].end());
		if (max < arr[i][0]) {
			max = arr[i][0];
		}
	}

	cout << max <<'\n';

}
