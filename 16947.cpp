#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N;
stack<int> s;
int dfsn[3005] , dist[3005];
bool finished[3005], isCycle[3005];
int num = 1;
vector<int> adj[3005];
// 타잔 알고리즘으로 사이클 먼저 구함
int getCycle(int cur , int prev){
    dfsn[cur] = num++;

    int ret = dfsn[cur];
    s.push(cur);
    for(int & next : adj[cur]){
        if(prev == next) continue;

        if(dfsn[next] == 0)
            ret = min(ret , getCycle(next , cur));
        else if(!finished[next])
            ret = min(ret , dfsn[next]);
    }

    if(ret == dfsn[cur]){
        vector<int> scc;
        while(1){
            int d = s.top();s.pop();
            scc.push_back(d);
            if(d == cur) break;
        }

        if(scc.size() > 1)
            for(int i = 0;i<scc.size();i++)
                isCycle[scc[i]] = 1;
        
    }
    finished[cur] = 1;
    return ret;
}

// 순환선과의 거리
void getDist(int cur , int d){
    dist[cur] = d;

    for(int & next : adj[cur]){
        if(dist[next] == -1){
            if(isCycle[next]) getDist(next , d);
            else getDist(next , d + 1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    getCycle(1 , 0);

    for(int i = 1;i<=N;i++)
        dist[i] = -1;

    for(int i = 1;i<=N;i++){
        if(isCycle[i]){
            getDist(i,0);
            break;
        }
    }

    for(int i = 1;i<=N;i++)
        cout<<dist[i]<<" ";


}