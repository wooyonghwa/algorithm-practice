#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {

	int N = 5;

	vector<int> arr = { 2,3,1,2,2};
	//정렬
	sort(arr.begin(), arr.end());

	//여행을 떠날 수 있는 그룹 결과
	int resultGroupCnt = 0;
	//그룹 수 카운트
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt++;
		//만약 그룹 카운트가 최소 공포도 명수를 채웠으면
		if (cnt >= arr[i]) {
			resultGroupCnt++; //그룹 수 증가
			cnt = 0;
		}

	}
	cout << resultGroupCnt << '\n';

}
