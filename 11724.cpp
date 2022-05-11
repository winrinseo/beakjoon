#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> adj[1005];
bool visited[1005];
void dfs(int cur){
    visited[cur] = true;
    for(int& next : adj[cur])
        if(!visited[next])
            dfs(next);
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1;i<=N;i++){
        if(!visited[i]){
            ans++;
            dfs(i);
        }
    }
    cout<<ans;
}