#include <iostream>
#define ll long long
using namespace std;
int N,Q;
int k = 1;
ll seg[4111];
void upd(int i,int d){
    i += k;
    seg[i] = d;
    while(i){
        i/=2;
        seg[i] = seg[(i<<1)]+seg[(i<<1)|1];
    }
}
ll sum(int idx,int st,int ed,int l,int r){
    if(r<st||ed<l) return 0;
    if(l<=st&&ed<=r) return seg[idx];
    int mid = (st+ed)/2;
    return sum(idx*2,st,mid,l,r)+sum(idx*2+1,mid+1,ed,l,r);
}
ll sum(int l,int r){
    return sum(1,0,k-1,l,r);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    while(k < N) k<<=1;
    for(int i = 0;i<N;i++){
        ll a;cin>>a;
        upd(i,a);
    }
    for(int i = 0;i<Q;i++){
        int cmd,a,b,c,d;
        cin>>cmd;
        if(cmd==1){
            cin>>a>>b;
            a--;b--;
            cout<<sum(a,b)<<"\n";
            ll temp = seg[a+k];
            upd(a,seg[b+k]);
            upd(b,temp);
        }else{
            cin>>a>>b>>c>>d;
            a--;b--;c--;d--;
            cout<<sum(a,b)-sum(c,d)<<"\n";
        }
    }
}