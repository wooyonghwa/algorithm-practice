#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers);
int main(void) {
	vector<int> numbers = { 5,0,2,7 };
	vector<int>::iterator iter;
	vector<int> result = solution(numbers);
	for (auto num : result) {
		cout << num << ' ';
	}
	return 0;
}
vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	set<int> answ;
	for (int i = 0; i < numbers.size() - 1; i++) {
		for (int j = i+1; j < numbers.size(); j++) {
			answ.insert(numbers[i] + numbers[j]);
		}
	}
	answer.assign(answ.begin(), answ.end());
	return answer;
}