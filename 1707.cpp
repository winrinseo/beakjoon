#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int K;
int visited[20005];
vector<int> adj[20005];
bool flag = true;
void dfs(int cur,int f){
    visited[cur] = f;
    for(int next : adj[cur]){
        if(flag==false) return;
        if(visited[next]==f){
            flag = false;
            return;
        }
        if(!visited[next])
            dfs(next,-f);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    while(K--){
        flag = true;
        for(int i = 0;i<20005;i++)
            adj[i].clear();
        memset(visited,0,sizeof(visited));
        int a,b;cin>>a>>b;
        for(int i = 0;i < b;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1;i<=a;i++){
            if(!visited[i])
                dfs(i,1);
            if(!flag) break;  
        }
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}