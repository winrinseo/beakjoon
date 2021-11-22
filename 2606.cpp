#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N,M;
vector<int> adj[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool visited[105] = {0};
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int answer = 0;
    while(!q.empty()){
        int curr = q.front();q.pop();
        for(int i = 0;i<adj[curr].size();i++){
            int next = adj[curr][i];
            if(visited[next]) continue;
            visited[next] = true;
            q.push(next);
            answer++;
        }
    }
    cout<<answer;
}