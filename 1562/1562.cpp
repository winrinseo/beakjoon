#include <iostream>
#include <vector>
#define MOD 1000000000
using namespace std;
int N;
//[n][bit]
long long memorise[101][11][1025];

long long dp(int depth,int poss,int prev) {
	if (depth == N && poss == (1 << 10) - 1) 
		return 1;
	if (depth >= N)
		return 0;
	long long &ret = memorise[depth][prev==-1?10:prev][poss];
	if (ret != -1) return ret%MOD;
	ret = 0;
	
	for (int i = 0; i < 10; i++) {
		if (prev == -1 && i == 0)
			continue;
		if (prev!=-1 && abs(prev - i) == 1)
			ret += dp(depth + 1, poss | (1<<i) , i);
		else if(prev==-1)
			ret += dp(depth + 1, poss | (1 << i), i);
	}
	return ret%MOD;
}

int main() {
	int n;
	cin >> n;
	N = n;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 11; j++)
			for(int z = 0;z<1025;z++)
				memorise[i][j][z] = -1;
	long long answer = dp(0,0,-1)%MOD;

	cout << answer;
}