#include <iostream>

using namespace std;
using ll = long long;
ll l[100005],cnt;
double seg[404040],lazy[404040];
int H,Q,R;
ll search(ll target){
    int lo = 1,hi = 100002;
    int ret = -1;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(target<l[mid]){
            hi = mid-1;
        }else{
            ret = mid;
            lo = mid+1;
        }
    }
    return ret;
}
void propagate(int idx,int st,int ed){
    if(lazy[idx]!=0){
        if(st!=ed){
            lazy[idx*2]+=lazy[idx];
            lazy[idx*2+1]+=lazy[idx];
        }
        seg[idx] += lazy[idx]*(ed-st+1);
        lazy[idx] = 0;
    }
}
void upd(int idx,int st,int ed,int l,int r,double diff){
    propagate(idx,st,ed);
    if(r<st||ed<l) return;
    if(l<=st&&ed<=r){
        lazy[idx]+=diff;
        propagate(idx,st,ed);
        return;
    }
    ll mid = (st+ed)/2;
    upd(idx*2,st,mid,l,r,diff);
    upd(idx*2+1,mid+1,ed,l,r,diff);
    seg[idx] = seg[idx*2]+seg[idx*2+1];
    return;
}
double sum(int idx,int st,int ed,int l,int r){
    propagate(idx,st,ed);
    if(r<st||ed<l) return 0;
    if(l<=st&&ed<=r) return seg[idx];
    ll mid = (st+ed)/2;
    return sum(idx*2,st,mid,l,r)+
        sum(idx*2+1,mid+1,ed,l,r);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>H;
    cin>>Q>>R;
    cout<<fixed;
    cout.precision(5);
    l[1] = cnt = 1;
    for(int i = 2;i<=100004;i++)
        l[i] = l[i-1] + cnt++;
    for(int i = 0;i<Q;i++){
        ll t,n;
        cin>>t>>n;
        ll level = search(t);
        ll s = H-level+1;
        //범위에 더해질 갯수
        double d = (double)n/(s+1);
        //범위시작지점
        ll S = t-l[level]+1;
        //[S,S+s]의 범위에 d를 더함
        upd(1,1,H+1,S,S+s,d);
    }
    for(int i = 0;i<R;i++){
        ll a,b;cin>>a>>b;
        cout<<sum(1,1,H+1,a,b)<<"\n";
    }
}