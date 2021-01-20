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
	int M; //����
	int N; //����
	int K; //���� ��ġ ����
	int X; //���� ���� ��ġ
	int Y; //���� ���� ��ġ
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
					//���� ����� ���߸�
					visited[i][j] = 1;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						int lx = q.front().first;
						int ly = q.front().second;
						//queue���� ���ְ�
						q.pop();
						for (int k = 0; k < 4; k++) {
							int dx = lx + dxdy[k][0];
							int dy = ly + dxdy[k][1];
							if (dx >= 0 && dx <= M && dy >= 0 && dy <= N) {
								//���߰� �ְ� �湮�ߴ� ���� �ƴϸ�
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