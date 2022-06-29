#include <iostream>
using namespace std;

int dp[200005][20];
int N,M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1;i<=N;i++)
        cin>>dp[i][0];
    
    for(int i = 1;i<20;i++){
        for(int j = 1;j<=N;j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    cin>>M;
    for(int i = 0;i<M;i++){
        int x,here;
        cin>>x>>here;
        for(int j = 0;j<20;j++){
            if(x & 1<<j){
                here = dp[here][j];
            }
        }
        cout<<here<<"\n";
    }
}