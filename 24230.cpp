#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int N;
int wc[200005];
vector<int> adj[200005];
bool visited[200005];
int answer = 0;
void dfs(int curr,int p){
    if(wc[p]!=wc[curr]) answer++;
    visited[curr] = true;
    for(int& next : adj[curr]){
        if(!visited[next])
            dfs(next,curr);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1;i<=N;i++) cin>>wc[i];

    for(int i = 0;i<N-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cout<<answer;
}