#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
vector<pair<int,int>> adj[10005];
vector<int> parent[10005];
int time[10005];
int indegree[10005];
//중복된 도로 체크
bool visited[10005][10005];
int dfs(int src) {
	int ret = 0;
	for (int i : parent[src]) {
		if (!visited[src][i]) {
			visited[src][i] = true;
			ret += (dfs(i) + 1);
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	queue<int> q;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		indegree[b]++;
	}
	for (int i = 0; i < N; i++)
		if (indegree[i] == 0) q.push(i);

	while (!q.empty()) {
		if (q.empty()) break;
		int curr = q.front();
		q.pop();
		for (auto next : adj[curr]) {
			--indegree[next.first];
			if (indegree[next.first] == 0)
				q.push(next.first);
			if (time[next.first] < time[curr] + next.second) {
				time[next.first] = time[curr] + next.second;
				//경로 역추적을 위한 그래프
				parent[next.first].clear();
				parent[next.first].push_back(curr);
			}
			else if (time[next.first] == time[curr] + next.second) {
				parent[next.first].push_back(curr);
			}
		}
	}
	int src, dst;
	cin >> src >> dst;
	cout << time[dst]<<'\n';
	cout << dfs(dst);
}