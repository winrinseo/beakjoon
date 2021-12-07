#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
int N,M;
ll arr[100005];
ll seg[400005];
ll init(int idx,int st,int ed){
    if(st==ed){
        return seg[idx] = arr[st];
    }
    int mid = (st+ed)/2;
    return seg[idx] = init(idx*2,st,mid)+init(idx*2+1,mid+1,ed);
}
ll sum(int idx,int st,int ed,int l,int r){
    if(r<st||ed<l) return 0;
    if(l<=st&&ed<=r) return seg[idx];
    int mid = (st+ed)/2;
    return sum(idx*2,st,mid,l,r)+sum(idx*2+1,mid+1,ed,l,r);
}
ll upd(int idx,int st,int ed,int i ,int diff){
    if(ed<i||i<st) return seg[idx];
    if(st==ed){
        return seg[idx] = diff;
    }
    int mid = (st+ed)/2;
    return seg[idx] = upd(idx*2,st,mid,i,diff)+upd(idx*2+1,mid+1,ed,i,diff);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 1;i<=N;i++){
        cin>>arr[i];
    }
    init(1,1,N);
    for(int i = 0;i<M;i++){
        int x,y,a; ll b; cin>>x>>y>>a>>b;
        if(x>y) swap(x,y);
        cout<<sum(1,1,N,x,y)<<"\n";
        arr[a] = b;
        upd(1,1,N,a,b);
    }
}