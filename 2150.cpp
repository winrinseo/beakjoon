#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, M;
vector<int> adj[10005];
//강결합에 속한 정점
bool finished[10005];
//정점 번호
int dfsn[10005];
stack<int> s;
int num = 0;
vector<vector<int>> SccAll;
int scc(int src) {
	dfsn[src] = ++num;
	s.push(src);
	int result = dfsn[src];

	for (int there : adj[src]) {
		//방문하지 않은 노드라면
		if (dfsn[there] == 0) result = min(result, scc(there));
		//방문은 했지만 강결합으로 추출되지않은 정점
		else if (!finished[there]) result = min(result, dfsn[there]);
	}
	//자식 정점에서 올라올 수 있는 정점이 자기 자신인 경우
	if (result == dfsn[src]) {
		vector<int> Scc;
		while (true) {
			//스택에서 자신이 나올 때 까지
			int a = s.top();
			s.pop();
			Scc.push_back(a);
			finished[a] = true;
			if (a == src) break;
		}
		sort(Scc.begin(), Scc.end());
		SccAll.push_back(Scc);
	}
	return result;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for(int i =1;i<=N;i++) if(dfsn[i]==0) scc(i);

	sort(SccAll.begin(), SccAll.end());
	cout << SccAll.size() << "\n";
	for (int i = 0; i < SccAll.size(); i++) {
		for (int j = 0; j < SccAll[i].size(); j++) {
			cout << SccAll[i][j] << " ";
		}
		cout << -1 << '\n';
	}
}