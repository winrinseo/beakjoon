#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, M,K;
int src, dst;
vector<pair<int,int>> adj[1005];
int dist[1005][1005];
int answer = INF;
struct Point {
	int here, dist, cnt;
};
struct cmp {
	bool operator()(Point& a, Point& b) {
		return a.dist > b.dist;
	}
};
void dijk() {
	
	priority_queue<Point,vector<Point>,cmp> pq;
	pq.push({ src,0,0 });
	dist[src][0] = 0;

	while (!pq.empty()) {
		int hhere = pq.top().here;
		int hdist = pq.top().dist;
		int hcnt = pq.top().cnt;
		pq.pop();
		if (dist[hhere][hcnt] < hdist) continue;
		for (int i = 0; i < adj[hhere].size(); i++) {
			int next = adj[hhere][i].first;
			int nd = adj[hhere][i].second;
			if (dist[next][hcnt+1] > hdist + nd) {
				dist[next][hcnt+1] = hdist + nd;
				pq.push({ next,hdist+nd, hcnt + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	cin >> src >> dst;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < N; j++)
			dist[i][j] = INF;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	dijk();
	for (int j = 1; j < N; j++) {
		answer = min(answer, dist[dst][j]);
	}
	cout << answer << "\n";
	int pay = 0;
	for (int i = 0; i < K; i++) {
		int rise; cin >> rise;
		pay += rise;
		answer = INF;
		for (int j = 1; j < N; j++) {
			answer = min(answer, dist[dst][j]+pay*j);
		}
		cout << answer << "\n";
	}

}