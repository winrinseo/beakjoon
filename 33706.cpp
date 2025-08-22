#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int N,M;
vector<int> adj[200005];
bool visited[200005];
void dfs(int cur){
    visited[cur] = true;
    for(int & next : adj[cur])
        if(!visited[next] && next > cur)
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
    for(int i = 1;i<=N;i++)
        sort(adj[i].begin() , adj[i].end());

    dfs(1);

    for(int i = 1;i<=N;i++){
        if(!visited[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}