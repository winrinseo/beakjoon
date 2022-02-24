#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int T,N;
int p[505];
int dp[505][505];
int psum[505];
int solve(int lo,int hi){
    if(lo==hi)
        return dp[lo][hi] = p[lo];
    
    int& ret = dp[lo][hi];
    if(ret!=INF) return ret;

    for(int i = lo;i < hi;i++){
        ret = min(ret,solve(lo,i)+solve(i+1,hi));
    }
    if(!(lo==0&&hi==N-1)) ret += (psum[hi]-psum[lo-1]);
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;

    while(T--){
        cin>>N;
        for(int i = 0;i<505;i++)
            fill(dp[i],dp[i]+N,INF);
        for(int i = 0;i<N;i++)
            cin>>p[i];
        psum[0] = p[0];
        for(int i = 1;i<N;i++)
            psum[i] = p[i]+psum[i-1];
        cout<<solve(0,N-1)<<"\n";

    }
}