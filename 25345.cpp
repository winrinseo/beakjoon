#include <iostream>
#define mod 1000000007
using namespace std;
int N,K;
int dp[2005][2005];
int solve(int n,int k){
    if(n == k || k == 0) return 1;
    if(k == 1) return n;
    if(dp[n][k] != 0) return dp[n][k]%=mod;
    return dp[n][k] = (solve(n-1,k)%mod + solve(n-1,k-1)%mod) % mod;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
    }
    
    long long ret = solve(N,K)%mod;
    for(int i = 0; i<K-1;i++) ret = ret*2%mod;
    cout<<ret%mod;
}