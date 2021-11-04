#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[1000005];
int L[1000005];
int D[1000005];
vector<int> answer;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	int len = 0;
	for (int i = 1; i <= N; i++) {
		auto pos = lower_bound(L + 1, L + len + 1, arr[i]);
		*pos = arr[i];
		D[i] = distance(L, pos);
		//들어갈 자리가 없으면 pos는 다음인덱스
		if (pos == L + len + 1)
			len++;
	}
	cout << len<<'\n';
	for (int i = N; i >= 1;) {
		if (len == 0) break;
		if (D[i] == len) {
			answer.push_back(arr[i]);
			len--;
			i--;
		}
		else {
			i--;
		}
	}
	reverse(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
}