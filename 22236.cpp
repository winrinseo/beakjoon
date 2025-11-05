#include <iostream>
#define ll long long
using namespace std;

int D , MOD;
// 거리, 고도
ll dp[4005][4005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>D>>MOD;

    dp[0][0] = 1;

    for(int i = 1;i<D;i++){

        for(int j = 1;j<=D;j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        }
    }

    cout<<dp[D-1][1] % MOD;
}