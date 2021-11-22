#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int N;
int dp[5005];
/*int solve(int n){
    if(n < 0) return INF;
    if(n == 0) return 0;
    int& ret = dp[n];
    if(ret!=0) return ret;
    ret = min(solve(n-3)+1,solve(n-5)+1);
    return ret;
}*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    /*int answer = solve(N);
    if(answer>=INF) cout<<-1;
    else cout<<answer;*/
    dp[0]=0,dp[1]=INF,dp[2]=INF,dp[3]=1,dp[4]=INF;
    for(int i = 5;i<=N;i++){
        dp[i] = min(dp[i-5]+1,dp[i-3]+1);
    }
    if(dp[N]>=INF) cout<<-1;
    else cout<<dp[N]; 
}