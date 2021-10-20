#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX_N 18 
#define INF 987654321
using namespace std;
int N,M;
vector<pair<int, int>> adj[100005];
//부모노드를 저장할 희소배열
//parnet[n][k] : n노드의 2^k번째 조상
int parent[100005][18];
//n~2^k번 노드 까지의 도로중 최대값을 저장
int max_d[100005][18];
//n~2^k번 노드 까지의 도로중 최소값을 저장
int min_d[100005][18];
int depth[100005];

void dfs(int src) {
	for (int i = 0; i < adj[src].size(); i++) {
		int there = adj[src][i].first;
		int dist = adj[src][i].second;
		if (depth[there] == -1) {
			depth[there] = depth[src] + 1;
			parent[there][0] = src;
			max_d[there][0] = dist;
			min_d[there][0] = dist;
			dfs(there);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	memset(depth, -1, sizeof(depth));
	memset(parent, -1, sizeof(parent));
	memset(max_d, -1, sizeof(max_d));
	for (int i = 0; i < 100005; i++)
		fill(min_d[i], min_d[i] + MAX_N, INF);
	depth[0] = 0;
	dfs(0);
	for (int k = 0; k < MAX_N-1; k++) {
		for (int n = 1; n < N; n++) {
			if (parent[n][k] != -1) {
				parent[n][k + 1] = parent[parent[n][k]][k];
				max_d[n][k + 1] = max(max_d[n][k],max_d[parent[n][k]][k]);
				min_d[n][k + 1] = min(min_d[n][k], min_d[parent[n][k]][k]);
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		int u_max = -1, u_min = INF;
		int v_max = -1, v_min = INF;
		if (depth[u] < depth[v])
			swap(u, v);
		int diff = depth[u]-depth[v];
		//깊이 차이만큼 u의 위치를 움직임
		for (int j = 0; diff; j++) {
			u_max = max(u_max,max_d[u][j]);
			u_min = min(u_min, min_d[u][j]);
			if (diff % 2) u = parent[u][j];
			diff >>= 1;
		}
		//u와 v의 위치가 다르면 함께 부모노드로 올라감
		if (u != v) {
			
			for (int j = MAX_N - 1; j >= 0; j--) {
				//부모 노드가 같은 경우라면 이미 공통조상이므로 최초로 달라지는 구간을 찾는다
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u_max = max(u_max, max_d[u][j]);
					u_min = min(u_min, min_d[u][j]);
					v_max = max(v_max, max_d[v][j]);
					v_min = min(v_min, min_d[v][j]);
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			//마지막으로 부모노드와 연결된 간선까지 비교
			u_max = max(u_max, max_d[u][0]);
			u_min = min(u_min, min_d[u][0]);
			v_max = max(v_max, max_d[v][0]);
			v_min = min(v_min, min_d[v][0]);
			//현재 u,v의 부모가 같으므로 최소 공통조상은 현재 노드의 부모임
			u = parent[u][0];
		}
		int one = max(u_max, v_max);
		int two = min(u_min, v_min);
		//쿼리로 같은 정점이 들어왔을 경우에 대한 예외처리
		one = one == -1 ? 0 : one;
		two = two == INF ? 0 : two;
		cout << two << " " << one << '\n';
	}
}