#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
using namespace std;
int N;
struct Line {
	pair<int, int> a[2];
};
vector<Line> all;
int parent[3005];
int find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	parent[u] = v;
}
int ccw(pair<int,int>& a,pair<int,int>& b,pair<int,int>& c) {
	int ret = (b.first - a.first) * (c.second - a.second) - 
		(b.second- a.second) * (c.first- a.first);
	if (ret < 0) return 1;
	else if (ret > 0) return -1;
	return 0;
}
bool isCrossed(Line& a,Line& b) {
	bool ret = false;
	int checka = ccw(a.a[0], a.a[1], b.a[0]) * ccw(a.a[0], a.a[1], b.a[1]);
	int checkb = ccw(b.a[0], b.a[1], a.a[0]) * ccw(b.a[0], b.a[1], a.a[1]);
	if (checka<=0&&checkb<=0) {
		if (checka == 0 && checkb == 0) {
			if (a.a[0] <= b.a[1] && a.a[1] >= b.a[0])
				ret = true;
		}else
			ret = true;
	}	
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < 3005; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		pair<int, int> a[2];
		cin >> a[0].first >> a[0].second >>
			a[1].first >> a[1].second;
		sort(a, a + 2);
		all.push_back({ a[0],a[1] });
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//이미 같은 그룹에 속해있는 경우
			if (find(i) == find(j))
				continue;
			//교차한다면
			if (isCrossed(all[i], all[j])) {
				merge(i, j);
			}
		}
	}
	sort(parent, parent + N);
	int maxv = 0;
	int answer = 0;
	int group = 1;
	for (int i = 0; i < N; i++) {
		if (i >= 1 && parent[i - 1] != parent[i]) {
			answer = max(answer, maxv);
			group++;
			maxv = 0;
		}
		maxv++;
	}
	answer = max(answer, maxv);
	cout << group << "\n" << answer;
}