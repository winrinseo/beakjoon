#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
using ll = long long;
int N,M,P;
int src,dst;
vector<pair<int,ll>> adj[100005];
bool nec[100005];
ll dist[2][100005];
struct Point{
    ll dist; int c,necc;
};
struct cmp{
    bool operator()(Point& a,Point& b){
        return a.dist > b.dist;
    }
};
ll dij(){
    priority_queue<Point,vector<Point>,cmp> pq;
    fill(dist[0],dist[0]+100005,INT64_MAX);
    fill(dist[1],dist[1]+100005,INT64_MAX);

    if(nec[src]) pq.push({0,src,true});
    else pq.push({0,src,false});

    dist[pq.top().necc][src] = 0;
    while(!pq.empty()){
        Point curr = pq.top(); pq.pop();
        if(curr.necc&&curr.c == dst) return curr.dist;
        for(int i = 0;i < adj[curr.c].size();i++){
            int next = adj[curr.c][i].first;
            ll nd = curr.dist+adj[curr.c][i].second;
            bool flag = nec[next]? nec[next] : curr.necc;
            
            if(dist[flag][next] > nd){
                dist[flag][next] = nd;
                pq.push({nd,next,flag});
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i =0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin>>src>>dst;
    cin>>P;
    for(int i =0;i<P;i++){
        int a; cin>>a;
        nec[a] = true;
    }
    cout<<dij();
}