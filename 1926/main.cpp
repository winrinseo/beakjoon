#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
int board[505][505];
bool visited[505][505];
int d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
queue<pair<int, int>> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	int area = 0;
	int maxarea = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && board[i][j]) {
				q.push({ i,j });
				visited[i][j] = true;
				int b = 0;
				while (!q.empty()) {
					int hr = q.front().first;
					int hc = q.front().second;
					q.pop();
					b++;
					for (int z = 0; z < 4; z++) {
						int nr = hr + d[z][0];
						int nc = hc + d[z][1];
						if (nr >= N || nr < 0 || nc >= M || nc < 0)
							continue;
						if (board[nr][nc] == 0)
							continue;
						if (visited[nr][nc])
							continue;
						visited[nr][nc]=true;
						q.push({ nr, nc });
					}
				}
				maxarea = max(maxarea, b);
				area++;
			}

		}
	}
	cout << area << '\n' << maxarea;

}