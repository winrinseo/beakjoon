#include <iostream>
using namespace std;
int N;
long long dp[35];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    dp[0] = 1 , dp[2] = 3,dp[4] = 11;
    
    for(int i = 6;i<=N;i++){
        dp[i] = (3*dp[i-2]);
        //짝수 블록에선 무조건 두가지 방법씩 존재함
        for(int j = 4;j<=i;j+=2){
            dp[i] += 2*dp[i-j];
        }
    }
    cout<<dp[N];
}