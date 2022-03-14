#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define pii pair<int,int>
#define ll long long
#define tiii tuple<int,int,ll>
using namespace std;
int N;
vector<tiii> cooker;
vector<int> adj[1005];
vector<tiii> edge;
int parent[1005];
ll cal(int pa,int pb,int ca,int cb){
    return ((ll)ca+cb)/abs(pa-pb);
}
int find(int u){
    if(parent[u]==u)
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u,int v){
    u = find(u),v = find(v);
    if(u==v) return;
    parent[u] = v;
}
void dfs(int prev,int curr){
    
    for(int next : adj[curr]){
        if(next!=prev)
            dfs(curr,next);
    }
    //항상 부모가 져야한다.
    if(prev!=-1)
        cout<<prev<<" "<<curr<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1;i<=N;i++)
        parent[i] = i;
    for(int i = 1;i<=N;i++){
        //실력 , 인기
        int a,b;cin>>a>>b;
        cooker.emplace_back(i,a,b);
        for(int j = 1;j<i;j++){
            int pa = get<1>(cooker[i-1]),pb = get<1>(cooker[j-1]);
            int ca = get<2>(cooker[i-1]),cb = get<2>(cooker[j-1]);
            edge.emplace_back(i,j,cal(pa,pb,ca,cb));
            cout<<pa<<" "<<pb<<" "<<ca<<" "<<cb<<"\n";
        }
    }
    //최대값을 구해야하므로 cost가 큰 순으로 정렬
    sort(edge.begin(),edge.end(),[](tiii& a,tiii& b){
        return get<2>(a) > get<2>(b);
    });
    ll ret = 0;
    for(int i = 0;i<edge.size();i++){
        int u = get<0>(edge[i]) , v = get<1>(edge[i]);
        ll dist = get<2>(edge[i]);
        if(find(u)!=find(v)){
            ret+=dist;
            adj[u].push_back(v);
            adj[v].push_back(u);
            merge(u,v);
        }
    }
    cout<<ret<<"\n";
    dfs(-1,1);
}