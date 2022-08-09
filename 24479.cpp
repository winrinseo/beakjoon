#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,R;
vector<int> adj[100005];
int visited[100005];
int cnt = 1;
void dfs(int cur){
    
    for(int & next : adj[cur]){
        if(!visited[next]){
            visited[next] = ++cnt;
            dfs(next);
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>R;

    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i<=N;i++)
        sort(adj[i].begin(),adj[i].end());
    visited[R] = 1;

    dfs(R);
    for(int i = 1;i<=N;i++)
        cout<<visited[i]<<"\n";

}