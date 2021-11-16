#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int T,N,E;
using ll = long long;
ll v[20005];
vector<vector<pair<ll,ll>>> adj;
vector<int> path;

ll dp[20005];
ll p[20005];
ll maxprofit;
int dst;
int parent[20005];
ll dfs(int src, ll profit) {
	profit += v[src];
	//최대 수치가 이미 계산되어 있을때
	if (dp[src] != 0) return dp[src];
	dp[src] = v[src];
	if (maxprofit < profit) {
		maxprofit = profit;
		dst = src;
	}
	for (auto there : adj[src]) {
		//src를 루트로 하는 서브트리를 탐색했을 때 가장 이익인 수치
		dp[src] = max(dp[src], 
			(dfs(there.first,profit-there.second) - there.second + v[src]));
		if (p[there.first] < ll(dp[there.first] + profit - there.second)) {
			p[there.first] = ll(dp[there.first] + profit - there.second);
			parent[there.first] = src;
		}
		
	}
	return dp[src];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>T;
	while (T--) {
		cin >> N >> E;
		maxprofit = -1;
		dst = 0;
		path.clear();
		adj = vector<vector<pair<ll, ll>>>(N + 1);
		memset(dp, 0, sizeof(dp));
		memset(p, 0, sizeof(p));
		memset(parent, 0, sizeof(parent));
		for (int i = 1; i <= N; i++)
			cin >> v[i];
		for (int i = 0; i < E; i++) {
			ll a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({ b,c });
		}
		ll answer = dfs(1, 0);
		cout <<answer <<" ";
		//목적지 노드부터 1번까지의 경로를 path에 저장
		while (1) {
			path.push_back(dst);
			dst = parent[dst];
			if (dst == 0) break;
		}
		cout << path.size() << '\n';
		for (int i = path.size() - 1; i >= 0; i--)
			cout << path[i] << " ";
		cout << '\n';
	}
	
}