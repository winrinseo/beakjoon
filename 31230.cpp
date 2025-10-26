#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <set>
#define ll long long
#define pii pair<long long,long long>
using namespace std;
struct cmp{
    bool operator()(pii & a , pii & b){
        return a.second > b.second;
    }
};
int N,M,A,B;
vector<pii> adj[200005];
vector<int> back_track[200005];
ll dist[200005];
priority_queue<pii , vector<pii>,cmp> pq;

set<int> answer;

bool visited[200005];

void dfs(int cur){
    visited[cur] = 1;
    answer.insert(cur);
    if(cur == A) return;
    
    for(int i = 0;i<back_track[cur].size();i++){
        if(!visited[back_track[cur][i]])
            dfs(back_track[cur][i]);
    }
}

void dij(){
    pq.push({A,0});
    for(int i = 0;i<200005;i++)
        dist[i] = INT64_MAX;

    dist[A] = 0;
    while(!pq.empty()){
        pii cur = pq.top();pq.pop();

        if(dist[cur.first] < cur.second) continue;
        for(pii & next : adj[cur.first]){
            int n = next.first;
            ll nd = cur.second + next.second;
            
            if(dist[n] > nd){
                dist[n] = nd;
                pq.push({n , nd});
                back_track[n].clear();
                back_track[n].push_back(cur.first);
            }else if(dist[n] == nd){
                back_track[n].push_back(cur.first);
            }
            
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>A>>B;

    for(int i = 0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    dij();
    dfs(B);
    cout<<answer.size()<<"\n";
    for(auto it = answer.begin();it != answer.end();it++)
        cout<<*it<<" ";
}