#include <iostream>
#include <vector>
#define pii pair<int,int>
#define INF 987654321
using namespace std;
int N,one,two;
vector<pii> adj[100005];
int dist1[100005];
int answer = INF;
void dfs1(int p,int cur,int d){
    dist1[cur] = d;
    for(auto& next : adj[cur]){
        if(next.first != p){
            dfs1(cur,next.first,d+next.second);
        }
    }
}

void dfs2(int p,int cur,int d){
    answer = min(answer,d+dist1[cur]);
    for(auto& next : adj[cur]){
        answer = min(answer,d+dist1[next.first]);
        if(next.first != p){
            dfs2(cur,next.first,d+next.second);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>one>>two;
    for(int i = 0;i<N-1;i++){
        int a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs1(-1,one,0);
    dfs2(-1,two,0);
    cout<<answer;
}