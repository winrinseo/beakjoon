#include <iostream>
#define MAX 15
using namespace std;
int N;
int cost[15][15];
int dp[15][1<<15];
int solve(int cur,int p,int t){

    int & ret = dp[cur][t];
    if(ret != 0) return ret;
    for(int i = 0;i<N;i++)
    
        if(!(t & (1<<i)) && p <= cost[cur][i])
            ret = max(ret,solve(i,cost[cur][i],t | (1<<i))+1);
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        string a;cin>>a;
        for(int j = 0;j<N;j++){
            cost[i][j] = a[j]-'0';
        }
    }

    cout<<solve(0,0,1)+1;
}