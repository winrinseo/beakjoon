#include <iostream>
#define MAX 18
using namespace std;
int T,N,M;
int H = 1<<MAX;
int seg[(1<<MAX)*2];
int idx[200050];
void upd(int i,int diff){
    i += H;
    seg[i] = diff;
    while(i > 1){
        i/=2;
        seg[i] = seg[i*2]+seg[i*2+1];
    }
}
int sum(int idx, int st,int ed,int l,int r){
    if(r<st||ed<l) return 0;
    if(l<=st&&ed<=r) return seg[idx];
    int mid = (st+ed)/2;
    return sum(idx*2,st,mid,l,r)+sum(idx*2+1,mid+1,ed,l,r);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>M;
        fill(seg,seg+(1<<MAX)*2,0);
        int top = N-1;
        for(int i = 1;i<=N;i++){
            idx[i] = N-i;
            upd(N-i,1);
        }

        for(int i = 0;i<M;i++){
            int q;cin>>q;
            int curr = idx[q];
            upd(curr,0);
            cout<<sum(1,0,H-1,curr,H-1)<<" ";
            top++;
            upd(top,1);
            idx[q] = top;
        }
        cout<<"\n";
    }
}