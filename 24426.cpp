#include <iostream>
#define INF 1000000000
using namespace std;

int N;
int m[1005][1005];
long long dp[1005][1005][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    for(int i = 1;i<=N;i++){
        dp[i][0][0] = dp[0][i][0] = -INF;
        dp[i][0][1] = dp[0][i][1] = -INF;
        for(int j = 1;j<=N;j++){
            cin>>m[i][j];
        }
    }
    int r,c;
    cin>>r>>c;
    dp[r][c][0] = INF;
    dp[r][c][1] = -INF;
    dp[1][0][0] = dp[0][1][0] = 0;
    dp[1][0][1] = dp[0][1][1] = 0;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            dp[i][j][0] += max(dp[i-1][j][0] , dp[i][j-1][0]) + m[i][j];
            dp[i][j][1] += max(dp[i-1][j][1] , dp[i][j-1][1]) + m[i][j];
        }
    }

    cout<<dp[N][N][0] - INF <<" "<<dp[N][N][1];
}