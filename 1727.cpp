#include <iostream>
#include <algorithm>

using namespace std;
int N,M;
int m[1005] , f[1005];
int dp[1005][1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    for(int i = 1;i<=N;i++)
        cin>>m[i];
    for(int i = 1;i<=M;i++)
        cin>>f[i];

    sort(m+1 , m + 1 + N);
    sort(f+1 , f + 1 + M);
    

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(i == j) dp[i][j] = dp[i-1][j-1] + abs(m[i] - f[j]);
            else if(i > j) dp[i][j] = min(dp[i - 1][j] , dp[i-1][j-1] + abs(m[i] - f[j]));
            else if(i < j) dp[i][j] = min(dp[i][j - 1] , dp[i-1][j-1] + abs(m[i] - f[j]));
        }
    }

    cout<<dp[N][M];
    
}