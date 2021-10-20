#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> adj[500005];
int cash[500005];
bool rest[500005];
int dfsn[500005];
bool finished[500005];
int num = 0,SN = 0; int r, start;
//sccNum[x] x번 정점이 속한 scc의 번호
int sccNum[500005];
//scc의 cost
int sccCash[500005]; bool sccRest[500005];
//scc의 인접리스트
vector<int> sccAdj[500005];
stack<int> s;
int getScc(int src) {
	dfsn[src] = ++num;
	s.push(src);
	int result = dfsn[src];
	
	for (int there : adj[src]) {
		if (dfsn[there] == 0) result = min(result, getScc(there));
		else if (!finished[there]) result = min(result, dfsn[there]);
	}
	//scc 분리
	if (result == dfsn[src]) {
		while (true) {
			int t = s.top(); s.pop();
			sccNum[t] = SN;
			sccCash[SN] += cash[t];
			if (rest[t]) sccRest[SN] = true;
			finished[t] = true;
			if (t == src) break;
		}
		SN++;
	}
	return result;
}
int sccIndegree[500005];
//시작점에서 갈 수 있는 위치라면
bool srcTodst[500005];
//시작점부터 가지고 갈 수 있는 금액
int getCash[500005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= N; i++)
		cin >> cash[i];
	cin >> start >> r;
	for (int i = 0; i < r; i++) {
		int a; cin >> a;
		rest[a] = true;
	}
	for (int i = 1; i <= N;i++) if(dfsn[i]==0) getScc(i);

	//scc의 인접리스트
	int sccStart = -1;
	for (int i = 1; i <= N; i++) {
		if (i == start) sccStart = sccNum[i];
		for (int j : adj[i]) {
			//인접한 두 정점이 서로 다른 강결합에 속한다면
			if (sccNum[i] != sccNum[j]) {
				sccAdj[sccNum[i]].push_back(sccNum[j]);
				sccIndegree[sccNum[j]]++;
			}
		}
	}
	queue<int> q;
	for (int i = 0; i < SN; i++) {
		getCash[i] = sccCash[i];
		if (i == sccStart) srcTodst[i] = true;
		if (sccIndegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		//시작점에서 도달 할 수 있는 위치라면 금액을 갱신한다.
		for (int there : sccAdj[curr]) {
			if (srcTodst[curr]) {
				getCash[there] = max(getCash[there],getCash[curr] + sccCash[there]);
				srcTodst[there] = true;
			}
			if (--sccIndegree[there] == 0) q.push(there);
		}
	}
	int answer = 0;
	for (int i = 0; i < SN; i++) {
		//시작점에서 갈 수 있고 레스토랑이 있는 위치라면
		if (srcTodst[i] && sccRest[i])
			answer = max(answer, getCash[i]);
	}
	cout << answer;
}