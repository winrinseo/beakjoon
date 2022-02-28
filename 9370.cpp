#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;
int T;
int n,m,t;
int s,g,h;
vector<pii> adj[2005];
vector<int> dij(int src){
    vector<int> dist(n+1,INF);
    priority_queue<pii> pq;
    pq.push({0,src});
    dist[src] = 0;
    while(!pq.empty()){
        pii curr = pq.top(); pq.pop();
        for(auto next : adj[curr.second]){
            if(dist[next.first]>-(curr.first-next.second)){
                dist[next.first] = -(curr.first-next.second);
                pq.push({-dist[next.first],next.first});
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        cin>>n>>m>>t;
        cin>>s>>g>>h;
        for(int i = 0;i<2005;i++)
            adj[i].clear();
        
        for(int i = 0;i<m;i++){
            int a,b,d;cin>>a>>b>>d;
            adj[a].push_back({b,d});
            adj[b].push_back({a,d});
        }
        vector<int> s_start = dij(s);
        vector<int> g_start = dij(g);
        vector<int> h_start = dij(h);
        int gh = g_start[h];
        vector<int> an;
        for(int i = 0;i<t;i++){
            int a;cin>>a;
            if(s_start[a]==s_start[g]+gh+h_start[a])
                an.push_back(a);
            else if(s_start[a]==s_start[h]+gh+g_start[a])
                an.push_back(a);
        }
        sort(an.begin(),an.end());
        for(int a : an) cout<<a<<" ";
        cout<<"\n";
    }
}