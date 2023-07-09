#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
struct edge{
    int v,c,d;
};
struct Point{
    int cur,cost,dist;
    
};
struct cmp{
    bool operator()(Point& a,Point& b){
        return a.dist > b.dist;
    }
};
int T,N,M,K;
vector<edge> adj[105];
int dist[105][10005];
int dij(){
    for(int i = 0;i<=N;i++)
        for(int j = 0;j<=M;j++)
            dist[i][j] = INF;
        
    priority_queue<Point,vector<Point>,cmp> pq;
    dist[1][0] = 0;
    pq.push({1,0,0});

    while(!pq.empty()){
        Point curr = pq.top();pq.pop();
        if(dist[curr.cur][curr.cost] < curr.dist) continue;

        for(auto& next : adj[curr.cur]){
            int ncost = curr.cost+next.c;
            int ndist = curr.dist+next.d;
            if(ncost > M) continue;

            if(dist[next.v][ncost] > ndist){
                dist[next.v][ncost] = ndist;
                
                pq.push({next.v,ncost,ndist});
            }
        }
    }
    int answer = INF;
    for(int i = 0;i<=M;i++)
        answer = min(answer, dist[N][i]);
    return answer;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>M>>K;
        for(int i = 0;i<=N;i++) adj[i].clear();
        for(int i = 0;i<K;i++){
            int a,b,c,d;cin>>a>>b>>c>>d;
            adj[a].push_back({b,c,d});
        }
        int answer = dij();
        if(answer==INF) cout<<"Poor KCM"<<"\n";
        else cout<<answer<<"\n";
    }
}