#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int N,M;

vector<pii> adj[50005];
vector<int> dist(50005 , INF);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    
    for(int i = 0;i<M;i++){

        int a,b,c; cin>>a>>b>>c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    priority_queue<pii , vector<pii> , greater<pii>> pq;

    pq.push({0,1});

    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();

        
        for(pii & next : adj[cur.second]){

            if(dist[next.first] > next.second + cur.first){
                dist[next.first] = next.second + cur.first;
                pq.push({next.second + cur.first , next.first});
            }
        }
    }

    cout<<dist[N];
}