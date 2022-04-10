#include <iostream>
using namespace std;
int N;
long long dp[85];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N<=3){
        if(N==1) cout<<4;
        if(N==2) cout<<6;
        if(N==3) cout<<10;
        return 0;
    }
    dp[1] = dp[2] = 1;
    for(int i = 3;i<=N;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    cout<<dp[N]*3 + dp[N-1]*2 + dp[N-2]*2 + dp[N-3];
}