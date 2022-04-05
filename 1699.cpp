#include <iostream>

using namespace std;
int N;
int dp[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<100005;i++) dp[i] = 1e9;
    dp[0] = 0;
    for(int k = 1;;k++){
        int kk = k*k;
        if(kk > N) break;
        for(int i = kk;i<=N;i++){
            dp[i] = min(dp[i],dp[i-kk]+1);
        }
    }
    cout<<dp[N];
}