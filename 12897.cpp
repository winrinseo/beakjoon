#include <iostream>
#define MOD 1000000007
using namespace std;

int N;
int dp[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    dp[1] = 2;
    dp[2] = 8;

    for(int i = 3;i<=N;i++){
        dp[i] = dp[i-1] + ((2 * dp[i-1]) % MOD) + 2;
        dp[i] %= MOD;
    }
    cout<<dp[N];
}