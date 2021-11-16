#include <iostream>
#include <string.h>
using namespace std;
int N,K;
int p[100005];
int seg[400005];
int convert(int a) {
    if(a==0) return 0;
    if(a > 0) return 1;
    if(a < 0) return -1;
}
int init(int idx,int st,int ed){
    if(st==ed)
        return seg[idx] = convert(p[st]);
    int mid = (st+ed)/2;
    return seg[idx] = convert(init(idx*2,st,mid)*init(idx*2+1,mid+1,ed));
}
int upd(int idx,int st,int ed,int i,int diff){
    if(st>i||ed<i) return seg[idx];
    if(st == ed)
        return seg[idx] = diff;
    int mid = (st+ed)/2;
    return seg[idx] = convert(upd(idx*2,st,mid,i,diff)*upd(idx*2+1,mid+1,ed,i,diff));
}
int mul(int idx,int st,int ed,int l,int r){
    if(st>r||ed<l) return 1;
    if(st>=l&&r>=ed) return seg[idx];
    int mid = (st+ed)/2;
    return convert(mul(idx*2,st,mid,l,r)*mul(idx*2+1,mid+1,ed,l,r));
}  
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>N>>K){
        memset(p,1,sizeof(p));
        memset(seg,1,sizeof(seg));
        for(int i = 1;i <= N;i++){
            cin>>p[i];
        }
        init(1,1,N);
        for(int i = 0;i<K;i++){
            char a; int b , c;
            cin>>a>>b>>c;
            if(a=='C'){
                upd(1,1,N,b,c);
            }else{
                long long ret = mul(1,1,N,b,c);
                if(ret<0) cout<<'-';
                else if(ret>0) cout<<'+';
                else cout<<'0';
            }
        }
        cout<<"\n";
    }
    return 0;
}