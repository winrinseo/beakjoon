#include <iostream>
#include <algorithm>
using namespace std;

int N , M;

int map[105][105];
int dp[105][105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            cin>>map[i][j];
        }
    }
    dp[1][1] = map[1][1];

    for(int j = 2;j<=M;j++){
        for(int i = 1;i<=N;i++){
            if(i > j) break;
            dp[i][j] = max({dp[i-1][j-1] , dp[i][j-1] , dp[i+1][j-1]}) + map[i][j];
        }
    }

    cout<<dp[N][M];
}