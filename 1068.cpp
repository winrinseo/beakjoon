#include <iostream>
#include <vector>

using namespace std;
int N;
int p[55];
bool isdel[55],visited[55];
vector<int> adj[55];
int answer = 0;
void del_dfs(int curr){
    isdel[curr] = true;
    for(int next : adj[curr])
        del_dfs(next);
}
void dfs(int curr){
    visited[curr] = true;
    bool isleaf = true;
    for(int next : adj[curr]){
        if(!isdel[next]){
            isleaf = false;
            dfs(next);
        }
    }
    if(isleaf) answer++;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++){
        cin>>p[i];
        if(p[i]!=-1){
            adj[p[i]].push_back(i);
        }
    }
    int d;cin>>d;
    del_dfs(d);
    vector<int> root;
    for(int i = 0;i<N;i++)
        if(p[i]==-1)
            root.push_back(i);
    for(int i : root){
        if(!isdel[i]&&!visited[i])
            dfs(i);
    }
    cout<<answer;
}