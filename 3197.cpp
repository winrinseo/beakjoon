#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define ICE 987654321
using namespace std;
int d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<string> board;
vector<vector<int>> Reboard;
int R,C;
bool bfs(vector<pair<int, int>> swan,int days){
	vector<vector<bool>> visited(R, vector<bool>(C, false));
	queue<pair<int, int>> q;
	q.push(make_pair(swan[0].first,swan[0].second));
	visited[swan[0].first][swan[0].second] = true;
	while (!q.empty()) {
		int hy = q.front().first;
		int hx = q.front().second;
		q.pop();
		if (hy == swan[1].first && hx == swan[1].second) return true;
		for (int i = 0; i < 4; i++) {
			int ny = hy + d[i][0];
			int nx = hx + d[i][1];

			if (ny >= R || ny < 0 || nx >= C || nx < 0) continue;
			if (visited[ny][nx]) continue;
			if (Reboard[ny][nx]>days) continue;
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
	return false;
}
int main()
{
	int r, c;
	cin >> r >> c;
	board = vector<string>(r);
	R = r;
	C = c;
	for (int i = 0; i < r; i++)
			cin >> board[i];
	
	vector<vector<int>> reboard(r, vector<int>(c));
	vector<pair<int, int>> swan;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'L')
				swan.push_back(make_pair(i, j));
			if (board[i][j] != 'X') reboard[i][j] = 0;
			else reboard[i][j] = ICE;
		}
	}
	int mind = 0, maxd = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int mindays = ICE;
			if (reboard[i][j] == 0) continue;
			for (int z = 0; z < 4; z++) {
				int ny = i + d[z][0], nx = j + d[z][1];
				if (ny >= R || ny < 0 || nx >= C || nx < 0) continue;
				mindays = min(mindays, reboard[ny][nx]);
			}
			reboard[i][j] = mindays+1;
		}
	}
	for (int i = R-1; i >= 0; i--) {
		for (int j = C-1; j>=0; j--) {
			int mindays = ICE;
			if (reboard[i][j] == 0) continue;
			for (int z = 0; z < 4; z++) {
				int ny = i + d[z][0], nx = j + d[z][1];
				if (ny >= R || ny < 0 || nx >= C || nx < 0) continue;
				mindays = min(mindays, reboard[ny][nx]);
			}
			reboard[i][j] = mindays + 1;
			maxd = max(maxd, reboard[i][j]);
		}
	}
	Reboard = reboard;
	int answer = ICE;
	while (mind<=maxd) {
		int midd = (mind + maxd) / 2;
		bool flag = bfs(swan,midd);
		if (flag) {
			answer = min(answer,midd);
			maxd = midd-1;
		}
		else {
			mind = midd+1;
		}

	}
	cout<<answer;
}