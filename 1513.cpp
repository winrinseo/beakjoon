#include <iostream>
using namespace std;
int N,M,C;
int dp[55][55][55][55];
int orak[55][55];
const int mod = 1000007;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>C;

    for(int i = 0;i<C;i++){
        int a,b;cin>>a>>b;
        orak[a][b] = i+1;
    }
    if(orak[1][1]){
        dp[1][1][orak[1][1]][1] = 1;
    }else dp[1][1][0][0] = 1;
    
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(i==1&&j==1) continue;
            if(orak[i][j]){
                int k = orak[i][j];
                for(int b = 0;b<=k;b++)
                    for(int a = 1;a <= k; a++){
                        dp[i][j][k][a] += (dp[i-1][j][b][a-1]+dp[i][j-1][b][a-1])%mod;
                        dp[i][j][k][a]%=mod;
                    }

            }else{
                // dp[i][j][0][0] = (dp[i-1][j][0][0]+dp[i][j-1][0][0])%mod;
                for(int b = 0;b<=C;b++)
                    for(int a = 0;a <= C; a++){
                        dp[i][j][b][a] += (dp[i-1][j][b][a]+dp[i][j-1][b][a])%mod;
                        dp[i][j][b][a]%=mod;
                    }
            }

        }
    }

    for(int i = 0;i<=C;i++){
        int an = 0;
        for(int b = 0;b<=C;b++){
            an+=dp[N][M][b][i];
            an%=mod;
        }
        cout<<an%mod<<" ";
    }
}