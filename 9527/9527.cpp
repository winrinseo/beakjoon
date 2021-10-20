#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
ll A,B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;
	ll answer = 0;
	for (ll i = A; i <= B; i++) {
		ll a = __builtin_popcount(i);
		answer += a;
	}
	cout << answer;
}