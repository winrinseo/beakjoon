#include <iostream>
#include <algorithm>

using namespace std;
int T,N;
int p[2][100005];
int dp[2][100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        cin>>N;
        for(int i = 0;i<2;i++)
            fill(dp[i],dp[i]+100005,0);
        for(int i = 0;i<2;i++){
            for(int j = 0;j<N;j++)
                cin>>p[i][j];
        }
        dp[0][0] = p[0][0];
        dp[1][0] = p[1][0];

        for(int i = 1;i < N;i++){
            dp[0][i] = dp[1][i-1]+p[0][i];
            dp[1][i] = dp[0][i-1]+p[1][i];
            if(i>=2){
                dp[0][i] = max(dp[0][i],max(dp[0][i-2]+p[0][i],
                    dp[1][i-2]+p[0][i]));
                dp[1][i] = max(dp[1][i],max(dp[0][i-2]+p[1][i],
                    dp[1][i-2]+p[1][i]));
            }
        }
        cout<<max(dp[0][N-1],dp[1][N-1])<<"\n";
    }
    
}