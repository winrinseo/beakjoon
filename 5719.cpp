#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#define INF 987654321
#define pii pair<int,int>
using namespace std;


int N,M;
int S,D;
unordered_map<int,int> adj[505];
// int adj[505][505];
vector<int> back[505];
int dist[505];
bool visited[505];

int dij(){

    priority_queue<pii> pq;

    pq.push({0,S});

    dist[S] = 0;

    while(!pq.empty()){
        pii cur = pq.top();pq.pop();
        int cd = -cur.first;
        int cv = cur.second;
        if(cd > dist[cv]) continue;

        for(auto it = adj[cv].begin();it != adj[cv].end();it++){
            int nd = cd + it->second;
            int nv = it->first;

            if(dist[nv] == nd)
                back[nv].push_back(cv);
            
            if(dist[nv] > nd){
                dist[nv] = nd;
                back[nv].clear();
                back[nv].push_back(cv);
                pq.push({-nd , nv});
            }
        }
    }
    return dist[D];
}

void dfs(int cur){
    visited[cur] = 1;
    for(int & next : back[cur]){
        adj[next].erase(cur);
        if(!visited[next]){
            dfs(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin>>N>>M;
        if(N == 0 && M == 0)
            break;

        cin>>S>>D;
        
        for(int i = 0;i<N;i++){
            dist[i] = INF;
            visited[i] = 0;
            adj[i].clear();
            back[i].clear();
        }
        for(int i = 0;i<M;i++){
            int a,b,c; cin>>a>>b>>c;
            adj[a][b] = c;
        }
        dij();
        dfs(D);

        for(int i = 0;i<N;i++)
            dist[i] = INF;
        
        int ret = dij();

        if(ret == INF) cout<<-1<<"\n";
        else cout<<ret<<"\n";
    }
}