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
		//잃어버린 건 -1 해줌(여벌 체육복 가져온 사람이 도난 될 수 있어서)
		arr[lost[i]] -= 1;
	}
	for (int i = 0; i < reserve.size(); i++) {
		//남는건 1 그외는 0
		arr[reserve[i]] += 1;
	}

	//잃어버린 것들 중에서
	for (int i = 0; i < lost.size(); i++) {
		//왼쪽 애가 여유분이 있으면 그리구 자기 자신이 도난 당한거여야함
		if (lost[i] > 1 && arr[lost[i] - 1] == 1 && arr[lost[i]] == -1) {
			//왼쪽 애를 깍고 자기가 올라감
			arr[lost[i] - 1] -=1;
			arr[lost[i]]+=1;
		}
		//왼쪽애는 여유가 없고 오른쪽 애가 여유가 있으면
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