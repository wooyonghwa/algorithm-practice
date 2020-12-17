#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> answers);

int main(void) {
    vector<int> answer = { 1,2,3,4,5 };
    vector<int> result = solution(answer);
    for (auto num : result) {
        cout << num << " ";
    }
    return 0;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> firstSupoja = { 1, 2, 3, 4, 5 };
    vector<int> secondSupoja = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> thirdSupoja = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    //문제 맞힌 갯수
    int firstSupojaTotCnt = 0;
    int secondSupojaTotCnt = 0;
    int thirdSupojaTotCnt = 0;

    //수포자가 찍는 방식의 위치
    int firstSupojaAt = 0;
    int secondSupojaAt = 0;
    int thirdSupojaAt = 0;
    for (int i = 0; i < answers.size(); i++) {
        
        if (firstSupojaAt == firstSupoja.size()) {
            firstSupojaAt = 0;
        }
        if (secondSupojaAt == secondSupoja.size()) {
            secondSupojaAt = 0;
        }
        if (thirdSupojaAt == thirdSupoja.size()) {
            thirdSupojaAt = 0;
        }
        
        //정답이 같으면 카운트 증가
        if (firstSupoja.at(firstSupojaAt++) == answers[i]) {
            firstSupojaTotCnt++;
        }
        if (secondSupoja.at(secondSupojaAt++) == answers[i]) {
            secondSupojaTotCnt++;
        }
        if (thirdSupoja.at(thirdSupojaAt++) == answers[i]) {
            thirdSupojaTotCnt++;
        }
    }
   
    int maximum = max(firstSupojaTotCnt, max(secondSupojaTotCnt, thirdSupojaTotCnt));
    if (maximum == firstSupojaTotCnt) answer.push_back(1);
    if (maximum == secondSupojaTotCnt) answer.push_back(2);
    if (maximum == thirdSupojaTotCnt) answer.push_back(3);
    return answer;
}
