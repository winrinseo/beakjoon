#include <iostream>
#include <algorithm>
#define MAX 16
using namespace std;
using ll = long long;
int N,K;
ll p[20];
ll dp[20][1<<MAX];
ll solve(int prev,int state){
    if(state==(1<<N)-1) return 1;
    ll &ret = dp[prev][state];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i = 0;i<N;i++){
        if(state&(1<<i) || abs(p[prev]-p[i])<=K) continue;
        ret += solve(i,state|1<<i);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i = 0;i<20;i++) fill(dp[i],dp[i]+(1<<MAX),-1);
    for(int i =0;i<N;i++) cin>>p[i];
    ll answer = 0;
    for(int i =0;i<N;i++){
        answer+=solve(i,(0|1<<i));
    }
    cout<<answer;
}