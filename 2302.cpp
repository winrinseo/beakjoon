#include <iostream>

using namespace std;
int N,M;
int dp[45];
bool v[45];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    dp[0] = 1,dp[1] = 1;
    for(int i = 0;i<M;i++){
        int a;cin>>a;
        v[a] = 1;
    }

    for(int i = 2;i<=N;i++){
        if(v[i]||v[i-1]) dp[i] = dp[i-1];
        else{
            dp[i] += dp[i-1];
            dp[i] += dp[i-2];
        }
    }
    cout<<dp[N];
}