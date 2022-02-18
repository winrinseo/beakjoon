#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> adj[100001];
vector<bool> visited(1000001, false);

int longest=-1;
int dfs(int src) {
	vector<int> lo;
	visited[src] = true;
	if (adj[src].empty()) return 0;

	int ret = 0;

	for (int i = 0; i < adj[src].size(); i++) {
		int there = adj[src][i].first;
		if (visited[there]) continue;
		int dist = dfs(there);
		
		ret = max(ret,dist + adj[src][i].second);

		lo.push_back(dist + adj[src][i].second);
	}
	sort(lo.begin(),lo.end());
	if (lo.size() >= 2) {
		longest = max(longest, lo[lo.size() - 1] + lo[lo.size() - 2]);
	}
	else if(lo.size()==1){
		longest = max(longest, lo[0]);
	}
	return ret;
}

int main()
{
	int v;
	cin >> v;
	int maxv = 0;
	for (int i = 0; i < v; i++) {
		int s;
		cin >> s;
		int cnt = 0;
		while (true) {
			int a, b;
			cin >> a;
			if (a == -1) break;
			cin >> b;
			adj[s].push_back(make_pair(a,b));
			cnt++;
		}
		
	}
	int one = dfs(1);
	
	cout <<longest;
}