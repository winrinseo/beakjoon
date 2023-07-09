#include <iostream>

using namespace std;
int N;
int dp[1005][2];

int dfs(int s , int p){
    if(s == 0) return (p > 0) ? -1 : 1;
    int pidx = p > 0 ? 1 : 0;

    int & ret = dp[s][pidx];
    if(ret != 0) return ret;
    ret = p > 0 ? -1 : 1;
    if(p > 0){
        if(s-1 >= 0) ret = max(ret , dfs(s-1,-p));
        if(s-3 >= 0) ret = max(ret , dfs(s-3,-p));
    }else{
        if(s-1 >= 0) ret = min(ret , dfs(s-1,-p));
        if(s-3 >= 0) ret = min(ret , dfs(s-3,-p));
    }
    // cout<<ret<<"\n";
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    dfs(N,1);
    // cout<<dp[N][1]<<"\n";
    if(dp[N][1] == 1){
        cout<<"SK";
    }else{
        cout<<"CY";
    }
}