#include <iostream>
using namespace std;
long long dp[95];
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    dp[0] = 0,dp[1] = 1;
    for(int i = 2;i<=N;i++)
        dp[i] = dp[i-1]+dp[i-2];
    cout<<dp[N];
}