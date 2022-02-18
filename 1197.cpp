#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define INF 987654321;
using namespace std;
int V, E;

vector<pair<int, pair<int, int>>> edges;
struct disjoint_set {
	vector<int> parent;
	disjoint_set(int n) {
		parent.resize(n+1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (parent[u] == u)
			return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v)
			return;
		parent[u] = v;
	}
	
};

int solve() {
	disjoint_set s(V);
	sort(edges.begin(),edges.end());
	int ret = 0;

	for (int i = 0; i < edges.size();i++) {
		int u = edges[i].second.first, v = edges[i].second.second;
		if (s.find(u) == s.find(v))
			continue;

		s.merge(u, v);
		ret += edges[i].first;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b}});
	}
	cout << solve();
}