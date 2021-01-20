#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int non[50][50];
int visited[50][50];
int totalCnt;
int dxdy[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };

int main(void) {
	int testCase;
	int M; //가로
	int N; //세로
	int K; //배추 위치 개수
	int X; //배추 가로 위치
	int Y; //배추 세로 위치
	queue<pair<int, int>> q;
	cin >> testCase;
	while (testCase--) {
		cin >> M >> N >> K;
		while (K--) {
			cin >> X >> Y;
			non[X][Y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (non[i][j] == 1 && visited[i][j] != 1) {
					//만약 유기농 배추면
					visited[i][j] = 1;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						int lx = q.front().first;
						int ly = q.front().second;
						//queue에서 빼주고
						q.pop();
						for (int k = 0; k < 4; k++) {
							int dx = lx + dxdy[k][0];
							int dy = ly + dxdy[k][1];
							if (dx >= 0 && dx <= M && dy >= 0 && dy <= N) {
								//배추가 있고 방문했던 곳이 아니면
								if (non[dx][dy] == 1 && visited[dx][dy] != 1) {
									visited[dx][dy] = 1;
									q.push(make_pair(dx, dy));
								}
							}
						}
					}
					totalCnt++;
				}
			}
		}
		cout << totalCnt << '\n';
	}
}