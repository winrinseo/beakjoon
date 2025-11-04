#include <iostream>


using namespace std;
int N,K;
int dp[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    for(int i = 1;i<=N;i++)
        dp[i] = 1<<30;

    for(int i = 0;i<N;i++){
        int next = i + 1;

        if(next <= N) dp[next] = min(dp[next] , dp[i] + 1);

        next = i + i / 2;

        if(next <= N) dp[next] = min(dp[next] , dp[i] + 1);
    }
    
    if(dp[N] <= K) cout<<"minigimbob";
    else cout<<"water";
}   