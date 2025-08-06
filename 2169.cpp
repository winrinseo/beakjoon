#include <iostream>
#include <algorithm>
#define INF -987654321
using namespace std;
int N,M;

int m[1005][1005], dp[1005][1005][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 0;i<1005;i++){
        for(int j = 0;j<1005;j++){
            for(int z = 0;z<3;z++){
                dp[i][j][z] = INF;
            }
        }
    }

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            cin>>m[i][j];
        }
    }


    

    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = m[1][1];

    


    for(int i = 1;i<=N;i++){

        //위에서 온거
        if(i!=1)
            for(int j = 1;j<=M;j++){
                dp[i][j][0] = max({dp[i-1][j][0] + m[i][j],dp[i-1][j][1] + m[i][j],dp[i-1][j][2] + m[i][j]});
            }
        //왼쪽에서 온거
        for(int j = 1;j<=M;j++){
            dp[i][j][1] = max({dp[i][j-1][0] + m[i][j],dp[i][j-1][1] + m[i][j]});
        }

        //오른쪽에서 온거 (첫 행이라면 {1,1}에서 출발해야해서 생략)
        if(i != 1)
            for(int j = M;j>=1;j--){
                dp[i][j][2] = max({dp[i][j+1][0] + m[i][j],dp[i][j+1][2] + m[i][j]});
            }
    }

    cout<<max({dp[N][M][0],dp[N][M][1],dp[N][M][2]});
}