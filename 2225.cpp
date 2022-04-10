#include <iostream>
#define mod 1000000000
using namespace std;
int N,K;
int dp[205][205];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i = 0;i<=N;i++) dp[i][1] = 1;
    for(int k = 1;k<=K;k++){
        for(int i = 0;i<=N;i++){
            for(int a = 0;a<=i;a++){
                dp[i][k] += (dp[i-a][k-1]%mod);
                dp[i][k]%=mod;
            }
        }
    }
    cout<<dp[N][K]%mod;
}