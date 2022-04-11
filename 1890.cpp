#include <iostream>
using namespace std;
int N;
int board[105][105];
long long dp[150][150];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            cin>>board[i][j];
        
    dp[N-1][N-1] = 1;
    for(int i = N-1;i>=0;i--){
        for(int j = N-1;j>=0;j--){
            if(board[i][j]!=0){
                dp[i][j] += dp[i][j+board[i][j]];
                dp[i][j] += dp[i+board[i][j]][j];
            }
        }
    }
    cout<<dp[0][0];
}