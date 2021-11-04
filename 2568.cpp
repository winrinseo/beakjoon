#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N;
pair<int, int> line[100005];
int L[100005];
int D[100005];
set<int> answer;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		answer.insert(a);
		line[i] = {a,b};
	}
	sort(line+1, line+N+1);
	int len = 0;
	for (int i = 1; i <= N; i++) {
		auto pos = lower_bound(L + 1, L + len + 1, line[i].second);
		*pos = line[i].second;
		D[i] = distance(L, pos);
		//들어갈 자리가 없으면 pos는 다음인덱스
		if (pos == L + len + 1)
			len++;
	}
	cout << N - len<<'\n';
	for (int i = N; i >= 1;) {
		if (len == 0) break;
		if (D[i] == len) {
			answer.erase(line[i].first);
			len--;
			i--;
		}
		else {
			i--;
		}
	}
	for (auto a : answer)
		cout << a << "\n";
		
}