#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
using namespace std;
int N,M;
vector<pair<int,int>> adj[100005];
vector<int> trip;
//노드의 일련번호를 저장
int node2num[100005];
//일련번호->노드
int num2node[100005];
//노드번호의 trip 에서의 출현위치
int locate[100005];
bool visited[100005];
int dep[100005];
int num = 0;
void dfs(int src,int depth) {
	visited[src] = true;
	node2num[src] = num;
	num2node[num] = src;
	locate[src] = trip.size();
	dep[src] = depth;
	num++;
	trip.push_back(node2num[src]);
	for (int i = 0; i < adj[src].size(); i++) {
		int there = adj[src][i].first;
		int dist = adj[src][i].second;
		if (visited[there]) continue;
		dfs(there,depth+dist);
		trip.push_back(node2num[src]);
	}
}
//해당 구간에서 노드의 일련번호가 가장 작은 번호를 저장
//(해당 구간의 최소 공통 조상의 일련번호)
int seg[500005];
int init(int idx,int st,int ed) {
	if (st == ed) return seg[idx] = trip[st];
	int mid = (st + ed) / 2;
	return seg[idx] = min(init(idx * 2, st, mid), init(idx * 2 + 1, mid + 1, ed));
}
//해당 구간 내에서 가장 일련번호가 낮은 번호를 반환
int query(int idx,int st,int ed,int l,int r) {
	if (r < st || ed < l) return INF;
	if (l <= st && ed <= r) return seg[idx];
	int mid = (st + ed) / 2;
	return min(query(idx * 2, st, mid, l, r), query(idx * 2 + 1, mid + 1, ed, l, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b,c;
		cin >> a >> b>>c;
		adj[a].push_back({ b ,c});
		adj[b].push_back({ a ,c});
	}
	dfs(1,0);
	init(1, 0, trip.size() - 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		//trip내의 구간으로 표현
		int aa = locate[a], bb = locate[b];
		if (aa > bb) swap(aa, bb);
		int lca = num2node[query(1, 0, trip.size() - 1, aa, bb)];
		int answer = dep[a] + dep[b] - 2 * dep[lca];
		cout << answer << '\n';
	}
}