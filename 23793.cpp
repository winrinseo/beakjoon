#include <bits/stdc++.h>
#define pii pair<int,int>
#define INF 2000000005
using namespace std;
struct Point{
    int cur,d;
    bool v;
};
struct cmp{
    bool operator()(Point& a,Point& b){
        return a.d > b.d;
    }
};
int N,M,x,y,z;
vector<pii> adj[100005];
int dist[100005][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    for(int i = 1;i<=N;i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    cin>>x>>y>>z;
    priority_queue<Point,vector<Point>,cmp> pq;
    pq.push({x,0,0});
    dist[x][0] = 0;
    while(!pq.empty()){
        Point curr = pq.top();pq.pop();

        if(dist[curr.cur][curr.v]<curr.d) continue;

        for(auto& next:adj[curr.cur]){
            bool nv = next.first==y?true:curr.v;
            if(dist[next.first][nv]>curr.d+next.second){
                dist[next.first][nv] = curr.d+next.second;
                pq.push({next.first,curr.d+next.second,nv});
            }
        }
    }
    if(dist[z][1]!=INF) cout<<dist[z][1]<<" ";
    else cout<<-1<<" ";
    if(dist[z][0]!=INF) cout<<dist[z][0]<<" ";
    else cout<<-1<<" ";
}