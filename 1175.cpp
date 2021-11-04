#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
int d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
struct Point {
	int y, x, t, prevD;
};
struct cmp {
	bool operator() (Point& a, Point& b) {
		return a.t > b.t;
	}
};
vector<string> Board;
int N, M;

vector<vector<vector<int>>> bfs(pair<int, int> src,int pd) {
	vector<vector<vector<int>>> dist = 
		vector<vector<vector<int>>>(N,vector<vector<int>>(M,vector<int>(4,INF)));
	priority_queue<Point,vector<Point>,cmp> pq;
	pq.push({ src.first,src.second,0,pd });
	while (!pq.empty()) {
		Point curr = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int ny = curr.y + d[i][0];
			int nx = curr.x + d[i][1];
			
			if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
			if (curr.prevD == i) continue;
			if (Board[ny][nx] == '#') continue;
			if (dist[ny][nx][i] > curr.t + 1) {
				dist[ny][nx][i] = curr.t + 1;
				pq.push({ ny,nx,curr.t + 1,i });
			}
				
		}
	}
	return dist;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	pair<int, int> src;
	vector<pair<int, int>> dst;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			if (x == 'S') src = make_pair(i, j);
			if (x == 'C') dst.push_back(make_pair(i, j));
			board[i].push_back(x);
		}
	}
	Board = board;
	N = n;
	M = m;
	vector<vector<vector<int>>> srcTodst = bfs(src, -1);
	vector<vector<vector<int>>> dstTodst;
	int ans;
	//case1 : src에서 dst[0]을 먼저 간 경우
	int one = INF;
	for (int i = 0; i < 4; i++) {
		if (srcTodst[dst[0].first][dst[0].second][i] == INF) continue;
		dstTodst = bfs(dst[0], i);
		for (int j = 0; j < 4; j++) {
			if (dstTodst[dst[1].first][dst[1].second][j] == INF) continue;
			one = min(one, srcTodst[dst[0].first][dst[0].second][i] + dstTodst[dst[1].first][dst[1].second][j]);
		}
	}
	//case2 : src에서 dst[1]을 먼저 간 경우
	int two = INF;
	for (int i = 0; i < 4; i++) {
		if (srcTodst[dst[1].first][dst[1].second][i] == INF) continue;
		dstTodst = bfs(dst[1], i);
		for (int j = 0; j < 4; j++) {
			if (dstTodst[dst[0].first][dst[0].second][j] == INF) continue;
			two = min(two, srcTodst[dst[1].first][dst[1].second][i] + dstTodst[dst[0].first][dst[0].second][j]);
		}
	}
	ans = min(one, two);
	if (ans == INF) cout << -1;
	else cout << ans;
}