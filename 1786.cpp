#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
int N;
int answer = 0;
vector<int> getTable(string& m) {
	int M = m.size();
	vector<int> ret(M, 0);
	int begin = 1, matched = 0;
	while (begin + matched < M) {
		if (m[begin + matched] == m[matched]) {
			matched++;
			ret[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - ret[matched - 1];
				matched = ret[matched - 1];
			}
		}
	}
	return ret;
}
vector<int> kmp(string& desert, string& m) {
	int N = desert.size();
	int M = m.size();
	vector<int> pi = getTable(m);
	vector<int> ret;
	int begin = 0, matched = 0;
	while (begin <= N - M) {
		if (matched < M && desert[begin + matched] == m[matched]) {
			matched++;
			if (matched == M){
				ret.push_back(begin + 1);
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
				answer++;
			}
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	getline(cin, a);
	getline(cin, b);
	vector<int> ans = kmp(a, b);
	cout << answer << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}