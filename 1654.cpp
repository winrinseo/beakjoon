#include <iostream>
using namespace std;
using ll = long long;
int N,K;
ll lan[10005];
ll getnum(int length){
    ll get = 0;
    for(int i = 0;i<K;i++){
        if(lan[i]<length) continue;
        get+=(lan[i]/length);
    }
    return get;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    cin>>K>>N;
    for(int i =0;i<K;i++){
        cin>>lan[i];
    }
    ll answer = 0;
    ll lo = 1,hi = INT64_MAX-1;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        ll get = getnum(mid);
        if(get>=N){
            answer = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    cout<<answer;
}