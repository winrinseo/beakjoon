#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
int T;
int N,M;
vector<string> board;

int d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
struct Point {
	int r, c, open, map;
};
struct cmp {
	bool operator()(Point& a, Point& b) {
		return a.open > b.open;
	}
};
int dij(vector<pair<int, int>>& src) {
	vector<vector<vector<int>>> dist(105, vector<vector<int>>(105, vector<int>(3, INF)));
	priority_queue<Point, vector<Point>, cmp> pq;
	for (int i = 0; i < src.size(); i++) {
		pq.push({ src[i].first,src[i].second,0,i });
		dist[src[i].first][src[i].second][i] = 0;
	}
	int ret = INF;
	while (!pq.empty()) {
		Point curr = pq.top();
		pq.pop();
		//3명이 중간에 만났을 경우
		if (dist[curr.r][curr.c][0] != INF && dist[curr.r][curr.c][1] != INF &&
			dist[curr.r][curr.c][2] != INF) {
			int sol = dist[curr.r][curr.c][0] + dist[curr.r][curr.c][1] + dist[curr.r][curr.c][2];
			//문에서 만난경우 중복되는 카운트를 감소시킨다.
			if (board[curr.r][curr.c] == '#')
				ret = min(ret, sol - 2);
			ret = min(ret, sol);
		}
			
		for (int i = 0; i < 4; i++) {
			int nr = curr.r + d[i][0];
			int nc = curr.c + d[i][1];
			int nopen = curr.open;
			//범위 밖인 경우
			if (nr >= N + 2 || nr < 0 || nc >= M + 2 || nc < 0)
				continue;
			//벽인 경우
			if (board[nr][nc] == '*')
				continue;
			//문인 경우
			if (board[nr][nc] == '#')
				nopen++;
			//최단 거리를 문이 열린 횟수로 정의
			if (dist[nr][nc][curr.map] > nopen) {
				dist[nr][nc][curr.map] = nopen;
				pq.push({ nr,nc,nopen,curr.map });
			}
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	
	for (int tc = 0; tc < T; tc++) {
		cin >> N >> M;
		//바깥에서 출발할 수 있도록 맵을 한칸씩 크게 잡는다
		board = vector<string>(N + 2, string(M + 2, '.'));
		vector<pair<int, int>> src;
		//출발지
		src.push_back({0,0});
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> board[i][j];
				//죄수들 역시 각자 출발
				if (board[i][j] == '$')
					src.push_back({ i,j });
			}
		}
		cout << dij(src) << '\n';

	}

}