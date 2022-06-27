#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define INF 987654321
#define DOT 10
#define pii pair<int,int>
using namespace std;
int N;
vector<int> adj[500005];
ll num[500005];
//ett
int n = -1;
int s[500005],e[500005];
//ETT num에 해당하는 중위순회의 idx
int ett[500005];
vector<ll> inorder(1,DOT);
void dfs1(int cur,int p){
    s[cur] = ++n;
    for(int i = 0;i<adj[cur].size();i++){ 
        if(adj[cur][i] != p){
            dfs1(adj[cur][i],cur);
            if(i!=adj[cur].size()-1){
                ett[s[cur]] = inorder.size();
                inorder.push_back(num[cur]);
                inorder.push_back(DOT);
            }
        }
    }
    
    ett[s[cur]] = inorder.size();
    inorder.push_back(num[cur]);
    inorder.push_back(DOT);
    
    e[cur] = n;
}
//ETT의 특정 구간의 최소값 최대값을 저장, 중위순회의 범위
vector<pii> seg;
pii init(int idx,int st,int ed){
    if(st==ed)
        return seg[idx] = {ett[st],ett[ed]};
    int mid = (st+ed)/2;
    pii left = init(idx*2,st,mid);
    pii right = init(idx*2+1,mid+1,ed);
    return seg[idx] = {min(right.first,left.first),max(right.second,left.second)};
}
pii query(int idx,int st,int ed,int l,int r){
    if(r<st||ed<l) return {INF,-INF};
    if(l<=st&&ed<=r) return seg[idx];
    int mid = (st+ed)/2;
    pii left = query(idx*2,st,mid,l,r);
    pii right = query(idx*2+1,mid+1,ed,l,r); 
    return {min(right.first,left.first),max(right.second,left.second)};
}
//manacher
vector<int> A;
void manacher(){
    int size = inorder.size();
    int r=0,p=0;
    for(int i = 0;i<size;i++){
        if(i<=r){
            A[i] = min(A[p*2-i],r-i);
        }else A[i] = 0;

        while(i-A[i]-1>=0 && i+A[i]+1<size && inorder[i-A[i]-1]==inorder[i+A[i]+1])
            A[i]++;
        if(r < i+A[i]){
            r = i+A[i];
            p = i;
        }
    }
}
vector<int> answer;
//부분 팰린드롬 판별
void dfs(int cur,int p){
    if(s[cur]==e[cur]){
        answer.push_back(cur+1);
        return;
    }
    pii cover = query(1,0,n,s[cur]+1,e[cur]);
    int mid = (cover.first+cover.second)/2;
    int st = mid-A[mid];
    int ed = mid+A[mid];
    int left = cover.first - st;
    int right = ed-cover.second;
    // cout<<mid<<" "<<A[mid]<<" "<<cover.first<<" "<<cover.second<<" "<<A[mid]<<"\n";
    // cout<<cur<<"\n";
    // for(int i = cover.first;i<=cover.second;i++) cout<<inorder[i]<<" ";
    // cout<<"\n";
    if(left==right) answer.push_back(cur+1);
    for(int next : adj[cur]){
        if(next!=p){
            dfs(next,cur);
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    seg.resize(N*4);
    for(int i = 0;i<N;i++){
        cin>>num[i];
    }
    for(int i = 0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0;i<N;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    dfs1(0,-1);
    init(1,0,n);
    A.resize(inorder.size());
    manacher();
    dfs(0,-1);
    sort(answer.begin(),answer.end());
    // for(ll a : inorder) cout<<a<<" ";
    
    
    cout<<answer.size()<<"\n";
    for(int a:answer) cout<<a<<" ";
}