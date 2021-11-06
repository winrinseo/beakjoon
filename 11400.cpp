#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int N,M;
vector<int> adj[100005];
vector<pair<int,int>> cut;
int dfsn[100005];
bool finished[100005];
int num = 0;
int dfs(int src,int p){
    dfsn[src] = ++num;
    int res = dfsn[src];
    for(int next : adj[src]){
        if(next == p) continue;
        if(dfsn[next]==0) {
            int a = dfs(next,src);
            if(!finished[src]&&a > dfsn[src]){
                int s = src , n = next;
                if(src>next) swap(s,n);
                cut.push_back({s,n});
            }
            res = min(res,a);
            }
        else res = min(res,dfsn[next]);
    }
    finished[src] = true;
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i < M; i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1 , 0);
    sort(cut.begin(),cut.end());
    cout<<cut.size()<<"\n";
    for(int i = 0;i<cut.size();i++){
        cout<<cut[i].first<<" "<<cut[i].second<<"\n";
    }
}