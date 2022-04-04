#include <iostream>
#define mod 10007
using namespace std;
int N;
int dp[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    dp[1] = 1,dp[2] = 3;
    for(int i = 3;i<=N;i++){
        dp[i] = (dp[i-1]+(2*dp[i-2])) % mod;
    }
    cout<<dp[N];
}