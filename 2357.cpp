#include <iostream>
#include <algorithm>
#define INF 9876543210
#define MAX 100005
using namespace std;
int N,M;
int arr[MAX];
pair<int,int> seg[MAX*4];
pair<int,int> init(int node,int st,int ed){
    if(st==ed) return seg[node] = {arr[st],arr[st]};
    int mid = (st+ed)/2;
    pair<int,int> l = init(node*2,st,mid);
    pair<int,int> r = init(node*2+1,mid+1,ed);
    seg[node].first = min(l.first,r.first);
    seg[node].second = max(l.second,r.second);
    return seg[node];
}
pair<int,int> query(int node,int st,int ed,int l,int r){
    if(r < st||l > ed) return {INF,-1};
    if(l<=st&&ed<=r) return seg[node];
    int mid = (st+ed)/2;
    pair<int,int> left = query(node*2,st,mid,l,r);
    pair<int,int> right = query(node*2+1,mid+1,ed,l,r);
    return {min(left.first,right.first),max(left.second,right.second)};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i = 1;i<=N;i++){
        cin>>arr[i];
    }
    init(1,1,N);
    for(int i = 0;i<M;i++){
        int a,b; cin>>a>>b;
        pair<int,int> q = query(1,1,N,a,b);
        cout<<q.first<<" "<<q.second<<"\n";
    }
}