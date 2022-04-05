#include <iostream>
#define mod 1000000007
using namespace std;
int N,M;
bool board[1005][1005];
long long dp[1005][1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
            cin>>board[i][j];

    for(int i = 0;i<M;i++)
        if(board[N-1][i])
            dp[N-1][i] = 1;

    for(int i = N-2;i>=0;i--){
        for(int j = 0;j < M; j++){
            if(board[i][j]){
                for(int a = -1;a<=1;a++){
                    if((j+a >= 0 && j+a < M)&&dp[i+1][j+a]){
                        dp[i][j] += (dp[i+1][j+a]%mod);
                        dp[i][j]%=mod;
                    }
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0;i<M;i++){
        answer += (dp[0][i]%mod);
        answer%=mod;
    }
        
    cout<<answer%mod;
}