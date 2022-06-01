#include <iostream>
using namespace std;
int s,m;
int dp[2050];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>m;
    dp[0] = 1;
    for(int i = 1;i<=512;i*=2){
        for(int j = s;j>=i;j--){
            dp[j] = max(dp[j],dp[j-i]&1);
        }
    }
    
    for(int i = 0;i<20;i++){
        if(!(m & (1<<i))) continue;
        for(int j = s;j>=1023+(1<<i);j--){
            int a = 1<<i;
            dp[j] = max(dp[j],dp[j-a]&1);
        }
    }
    
    if(s > 1023&&dp[s]==1) cout<<"Thanks";
    else if(dp[s]==1) cout<<"No thanks";
    else cout<<"Impossible";
}