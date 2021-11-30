#include <iostream>
#include <algorithm>
#define INF 1111111111
using namespace std;
int N,M;
int arr[100005];
int seg[400005];
int mymin(int a,int b){
    if(a==-1) return b;
    if(b==-1) return a;
    if(arr[a]>arr[b]) return b;
    if(arr[b]>arr[a]) return a;
    if(arr[a]==arr[b]) return min(a,b);
}

int init(int idx,int st,int ed){
    if(st==ed){
        return seg[idx] = st;
    }
    int mid = (st+ed)/2;
    return seg[idx] = mymin(init(idx*2,st,mid),init(idx*2+1,mid+1,ed));
}
int upd(int idx,int st,int ed,int i,int diff){
    if(i < st||ed < i) return seg[idx];
    if(st==ed){
        arr[i] = diff;
        return seg[idx];
    }
    int mid = (st+ed)/2;
    return seg[idx] = mymin(upd(idx*2,st,mid,i,diff),upd(idx*2+1,mid+1,ed,i,diff));
}
int upd(int i,int diff){
    return upd(1,1,N,i,diff);
}
int query(int idx,int st,int ed,int l,int r){
    if(r < st||ed < l) return -1;
    if(l<=st&&ed<=r) return seg[idx];
    int mid = (st+ed)/2;
    return mymin(query(idx*2,st,mid,l,r),query(idx*2+1,mid+1,ed,l,r));
}
int query(int l,int r){
    return query(1,1,N,l,r);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1;i<=N;i++) cin>>arr[i];
    cin>>M;
    init(1,1,N);
    for(int i = 0;i<M;i++){
        int a,b,c; cin>>a>>b>>c;
        if(a==1){
            upd(b,c);
        }else{
            cout<<query(b,c)<<"\n";
        }
    }

}