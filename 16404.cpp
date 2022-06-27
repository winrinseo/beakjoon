#include <iostream>
#include <vector>
using namespace std;
int N,M;
int seg[400005],lazy[400005];
vector<int> adj[100005];
int s[100005],e[100005];
int n = -1;
void ett(int cur){
    s[cur] = ++n;
    for(int next : adj[cur]){
        ett(next);
    }
    e[cur] = n;
}
void propergate(int idx,int st,int ed){
    if(lazy[idx] != 0){
        if(st==ed){
            seg[idx] += lazy[idx];
        }else{
            lazy[idx*2]+=lazy[idx];
            lazy[idx*2+1]+=lazy[idx];
        }
        lazy[idx] = 0;
    }
}
void update(int idx,int st,int ed,int l,int r,int diff){
    if(r<st||ed<l) return;
    if(l<=st&&ed<=r){
        lazy[idx]+=diff;
        propergate(idx,st,ed);
        return;
    }
    int mid = (st+ed)/2;
    update(idx*2,st,mid,l,r,diff);
    update(idx*2+1,mid+1,ed,l,r,diff);
    
}
void query(int idx,int st,int ed,int q){
    propergate(idx,st,ed);
    if(q<st||ed<q) return;
    if(st==ed){
        propergate(idx,st,ed);
        cout<<seg[idx]<<"\n";
        return;
    }
    int mid = (st+ed)/2;
    query(idx*2,st,mid,q);
    query(idx*2+1,mid+1,ed,q);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 1;i<=N;i++){
        int a;cin>>a;
        if(a!=-1)
            adj[a].push_back(i);
    }
    ett(1);
    for(int i = 0;i<M;i++){
        int a,b,c;cin>>a;
        if(a==1){
            cin>>b>>c;
            update(1,0,N-1,s[b],e[b],c);
        }else{
            cin>>b;
            query(1,0,N-1,s[b]);
        }
    }
}