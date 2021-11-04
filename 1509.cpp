#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#define INF 987654321;
using namespace std;
string a;
int dp[2505];
int pel[2505][2505];
bool ispel(int lo,int hi) {
	if (pel[lo][hi]==1||pel[lo][hi] == 0)
		return pel[lo][hi];
	if (lo == hi)
		return pel[lo][hi] = true;
	if (a[lo] != a[hi]) return pel[lo][hi] = false;
	if (lo+1 == hi)
		return pel[lo][hi] = true;
	return pel[lo][hi] = ispel(lo+1,hi-1);
}
int solve(int pos) {
	if (pos >= a.size())
		return 0;
	int &ret = dp[pos];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = pos; i < a.size(); i++) {
		if (ispel(pos,i)) {
			ret = min(ret,solve(i + 1)+1);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a;
	memset(pel, -1, sizeof(pel));
	memset(dp, -1, sizeof(dp));
	cout<<solve(0);
}