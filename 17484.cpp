#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N,M;

int dp[10][10][3], m[10][10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0 ;i<10;i++)
        for(int j = 0; j<10;j++)
            for(int z = 0; z<3;z++)
                dp[i][j][z] = INF;
    
    
            
    for(int i = 1 ;i<=N;i++)
        for(int j = 1; j<=M;j++)
            cin>>m[i][j];


    for(int j = 1;j<=M;j++)
        for(int z = 0; z<3;z++)
            dp[1][j][z] = m[1][j];


    for(int i = 2;i <= N; i++){
        for(int j = 1;j<=M;j++){
            
            //이전에 중간으로 온 값
            dp[i][j][0] = min({dp[i][j][0] , dp[i - 1][j][1] + m[i][j] , dp[i - 1][j][2] + m[i][j]});
            //이전에 왼쪽으로 온 값
            dp[i][j][1] = min({dp[i][j][1] , dp[i - 1][j - 1][0] + m[i][j] , dp[i - 1][j - 1][2] + m[i][j]});
            dp[i][j][2] = min({dp[i][j][2] , dp[i - 1][j + 1][0] + m[i][j] , dp[i - 1][j + 1][1] + m[i][j]});
        }
    }

    int ans = INF;

    for(int i = 1;i<=M;i++)
        for(int j = 0;j<3;j++)
        ans = min(ans , dp[N][i][j]);

    cout<<ans;
}