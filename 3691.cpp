#include <iostream>
#include <map>
#include <tuple>
#include <queue>
#define INF 1000000001
#define pii pair<int,int>
#define tiii tuple<int,int,int>
using namespace std;
int T,N,B;
map<string,int> name;

int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>B;
        priority_queue<pii> adj[1005];
        name.clear();
        cnt = 0;
        for(int i = 0;i<N;i++){
            string t,nm;
            int p,q;
            cin>>t>>nm>>p>>q;
            
            if(!name.count(t))
                name[t] = cnt++;

            adj[name[t]].push({-p,q});

            
        }
        priority_queue<tiii> pq;
        int ret = 0;
        int total = 0;
        for(int i = 0;i<cnt;i++){
            pq.push({-adj[i].top().second,-adj[i].top().first,i});
            total+=(-adj[i].top().first);
            adj[i].pop();
        }

        while(total <= B){
            ret = max(ret,-get<0>(pq.top()));
            int type = get<2>(pq.top());
            total -= get<1>(pq.top());
            pq.pop();
            if(adj[type].empty()) break;
            total += -adj[type].top().first;
            
            pq.push({-adj[type].top().second,-adj[type].top().first,type});
            adj[type].pop();
        }
        cout<<ret<<"\n";
    }
    
}