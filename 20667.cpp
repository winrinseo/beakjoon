#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int N,M,K;
int dp[505][1005];//0 : p , 1 : cpu
int c[105],m[105],p[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(int i = 0;i<N;i++){
        cin>>c[i]>>m[i]>>p[i];
    }
    for(int i = 0;i<505;i++)
        for(int j = 0;j<1005;j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for(int i = 0;i < N; i++){
        for(int j = 500;j>=0;j--){
            for(int z = 1001;z>=0;z--){
                if(j+p[i] > 500) continue;
                if(z+c[i]<=1000){
                    dp[j+p[i]][z+c[i]] = max(dp[j+p[i]][z+c[i]],dp[j][z]+m[i]);
                }
                if(z+c[i]>1000){
                    dp[j+p[i]][1001] = max(dp[j+p[i]][1001],dp[j][z]+m[i]);
                }
            }
        }
    }
    int answer = -1;
    for(int i=0;i<=500;i++){
        for(int j = M;j<=1001;j++){
            if(dp[i][j]>=K){
                if(answer==-1||answer>i) answer = i;
            }
        }
    }

    cout<<answer;   
}