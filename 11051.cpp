#include <iostream>
#define mod 10007
using namespace std;
int N,K;
int dp[1005][1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i = 0;i<=N;i++){
        dp[i][0] = dp[i][i] = 1;
    }
    for(int n = 2;n<=N;n++){

        for(int k = 1;k<n;k++){
            dp[n][k] = (dp[n-1][k-1]+dp[n-1][k])%mod;
        }
    }
    cout<<dp[N][K];
}