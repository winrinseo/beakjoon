#include <iostream>
#include <vector>
#include <algorithm>
//s
using namespace std;

vector<vector<int>> adj;
vector<int> time;
vector<int> visited;

void topology(int src,vector<int>& sorted) {
	if (visited[src])
		return;
	for (int i = 0; i < adj[src].size(); i++) {
		topology(adj[src][i],sorted);
	}
	visited[src] = true;
	sorted.push_back(src);
}
int main() {
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		adj = vector<vector<int>>(1001);
		time = vector<int>(1001);
		visited = vector<int>(1001);
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			time[i + 1] = a;
		}
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			//간선의 방향을 거꾸로 한 그래프를 만든다.
			//정방향 위상정렬의 결과는 뒤집어야 하므로
			//뒤집지 않은 역방향 위상정렬의 결과와 동일
			adj[b].push_back(a);
		}
		int dst;
		cin >> dst;
		vector<int> sorted;
		topology(dst,sorted);
		for (int i = 0; i < sorted.size(); i++) {
			//부모 노드를 참조.
			int temp = time[sorted[i]];
			for (int j = 0; j < adj[sorted[i]].size(); j++) {
				//연결된 노드중 가장 큰 시간이 걸리는 것만을 저장
				temp = max(temp, time[sorted[i]] + time[adj[sorted[i]][j]]);
			}
			time[sorted[i]] = temp;
		}
		cout << time[dst]<<endl;
	}
}