#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
using ll = long long;
ll p[10005];
int answer = -1;
ll solve(ll t){
    //t 시간에 몇명의 대기열을 처리하는지 셈
    ll res = M;
    for(int i = 0;i<M;i++){
        res+=(t/p[i]);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ll maxt = -1;
    for(int i = 0;i<M;i++){
        cin>>p[i];
        maxt = max(maxt,p[i]);
    }
    if(N <= M) cout<<N;
    ll lo = 1, hi = maxt*N;
    ll t,n;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        ll num = solve(mid);
        if(num < N){
            lo = mid+1;
            t = mid;
            n = N-num;
        }else{
            hi = mid-1; 
        }
    }
    for(int i =0;i<M;i++){
        if((t+1)%p[i]==0) n--;
        if(n==0){
            cout<<i+1;
            return 0;
        }
    }
}