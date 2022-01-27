#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
using ll = long long;
pair<int,int> here[500005];
vector<ll> seg;
ll arr[500005];
ll upd(int idx,int st,int ed,int i){
    if(i<st||ed<i) return seg[idx];
    if(st==ed) return seg[idx]=1;
    int mid = (st+ed)/2;
    return seg[idx] = upd(idx*2,st,mid,i)+upd(idx*2+1,mid+1,ed,i);
}
ll sum(int idx,int st,int ed,int l,int r){
    if(r<st||ed<l) return 0;
    if(l<=st&&ed<=r) return seg[idx];
    int mid = (st+ed)/2;
    return sum(idx*2,st,mid,l,r)+sum(idx*2+1,mid+1,ed,l,r);
}
int binary(int target){
    int lo = 0, hi = N-1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(here[mid].first==target) return here[mid].second;
        else if(here[mid].first < target) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    seg = vector<ll>(N*4+5,0);
    for(int i = 0;i<N;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        here[i] = {a,i};
    }
    sort(here,here+N);
    ll answer = 0;
    for(int i = 0;i<N;i++){
        int idx = binary(arr[i]);
        answer += sum(1,0,N-1,idx,N-1);
        upd(1,0,N-1,idx);
    }
    cout<<answer;
}