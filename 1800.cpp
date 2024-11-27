#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

int N,P,K;
struct cmp{
    bool operator ()(vector<int> a , vector<int> b){
        return a[1] > b[1];
    }
};

vector<pii> adj[1005];
//{위치 , 간선 비용 최댓값 , 제한 초과 횟수}
priority_queue<vector<int> , vector<vector<int>> , cmp> pq;
int dist[1005];

bool dij(int k){
    
    for(int i = 1;i<=N;i++)
        dist[i] = INF;
    
    pq.push({1, 0});

    while(!pq.empty()){
        vector<int> cur = pq.top();
        pq.pop();

        for(pii & next : adj[cur[0]]){
            int nk = cur[1];
            //초과가 불가능하고 비용 최대치를 초과했을때
            if(cur[1] >= K && next.second > k)
                continue;
            
            if(next.second > k){
                nk++;
            }
            if(dist[next.first] > nk){
                dist[next.first] = nk;
                pq.push({next.first  , nk});
            }
        }
    }
    
    return dist[N] != INF;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>P>>K;

    for(int i = 0; i<P;i++){
        int a,b,c; cin>>a>>b>>c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    int lo = 0 , hi = 1000000;
    int ans = -1;
    while(lo <= hi){
        int k = (lo + hi)/2;

        //k 이하의 간선만으로 N까지 닿을 수 있는지 (k초과는 K번까지 가능)
        if(dij(k)){
            hi = k - 1;
            ans = k;
        }else{
            lo = k + 1;
        }
    }

    cout<<ans;
}