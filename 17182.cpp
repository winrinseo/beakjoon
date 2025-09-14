#include <iostream>
#define INF 987654321
using namespace std;

int N, K;
int dist[15][15];

int dp[15][(1<<10)-1];

int solve(int cur , int bit){

    if(bit == (1<<N) - 1) return 0;
    int & ret = dp[cur][bit];

    if(ret != 0) return ret;

    ret = INF;

    for(int i = 0;i<N;i++){
        if(!(bit & (1<<i))){
            ret = min(ret , solve(i , bit | (1<<i)) + dist[cur][i]);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin>>dist[i][j];
        }
    }

    for(int k = 0;k<N;k++)
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);

    
    cout<<solve(K, 0);
}