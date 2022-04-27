#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N,M;
vector<int> adj[505];
bool visited[505];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int answer = 0;

    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1] = true;
    while(!q.empty()){
        int cur = q.front().first;
        int dis = q.front().second;
        q.pop();
        
        for(int& next : adj[cur]){
            if(!visited[next]){
                if(dis+1 > 2) continue;
                visited[next] = true;
                answer++;
                q.push({next,dis+1});
            }
        }
    }
    cout<<answer;
}