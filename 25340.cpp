#include <iostream>
#define ll long long
using namespace std;
int TC,N,T;
ll A[300005],B[300005],C[300005],D[300005],E[300005];

ll mint(int i,ll t){
    //i번째 횡단 보도를 건널 수 있는 최소의 시간을 반환
    ll ret = t;
    ll lo = 0,hi = 1000000000;
    while(lo<=hi){
        ll x = (lo+hi)/2;
        ll open = C[i]+A[i]*x;
        ll close = (C[i]+A[i]*x+B[i]);
    
        if(open<=t && t+D[i]<=close){
            return t+D[i];
        }
        if(close < t+D[i]){
            lo = x+1;
        }else if(t<=open && open+D[i]<=close){
            
            ret = open;
            hi = x-1;
        }
    }
    
    return ret+D[i];
}

ll param(ll t){
    t += E[0];

    for(int i = 0;i<N;i++){
        t = mint(i,t);
        t+=E[i+1];
    }
    
    return t;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>TC;

    while(TC--){
        cin>>N>>T;
        for(int i = 0;i<N;i++){
            cin>>A[i]>>B[i]>>C[i]>>D[i];
        }
        for(int i = 0;i<N+1;i++){
            cin>>E[i];
        }
        //집에서 출발하는 시간
        ll lo = 0,hi = 1000000000;
        bool flag = false;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            
            ll p = param(mid);
            if(p > T){
                hi = mid-1;
            }else if(p < T){
                lo = mid+1;
            }else{
                flag = true;
                break;
            }
        }
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }

}