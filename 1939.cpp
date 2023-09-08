#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
int N,M;
vector<pii> adj[10005];
int S,D;

bool bfs(int k){
    queue<int> q;
    bool visited[10005] = {0};

    q.push(S);
    visited[S] = 1;

    while(!q.empty()){
        int cur = q.front();q.pop();
        if(cur == D) return true;
        for(auto& next : adj[cur]){
            if(visited[next.first])
                continue;

            if(next.second < k)
                continue;
            
            visited[next.first] = 1;
            q.push(next.first);
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin>>S>>D;
    int answer = -1;
    int lo = 0 , hi = 1000000000;
    while(lo <= hi){
        int mid = (lo + hi)/2;

        if(bfs(mid)){
            lo = mid+1;
            answer = mid;
        }else{
            hi = mid-1;
        }
    }
    cout<<answer;
}