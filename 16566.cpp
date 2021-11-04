#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M,K;
int arr[4000005];
struct disjoint_set {
	vector<int> perant;
	disjoint_set(int n) {
		perant.resize(n + 1);
		for (int i = 0; i <= n; i++)
			perant[i] = i;
	}
	int find(int u) {
		if (perant[u] == u)
			return u;
		return perant[u] = find(perant[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		perant[u] = v;
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
		cin >> arr[i];
	sort(arr, arr + M);
	disjoint_set s(N);
	for (int i = 0; i < K; i++) {
		int ee;
		cin >> ee;
		int lo = 0;
		int hi = M - 1;
		int my;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (ee < arr[mid]) {
				my = mid;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		int card = s.find(arr[my]);
		cout << card << '\n';
		s.merge(arr[my], *upper_bound(arr , arr+M , card));
	}
}