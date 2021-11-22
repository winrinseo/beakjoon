#include <iostream>
#include <vector>
using namespace std;
int N,M;
int ret = 0;
vector<int> adj[100005];
int discovered[100005];
bool finished[100005];
int num = 0;
void dfs(int src,int prev){
    discovered[src] = ++num;
    for(int next : adj[src]){
        if(next==prev) continue;
        if(discovered[next]==0){
            dfs(next,src);
        }else if(!finished[next]){
            ret++;
        }
    }
    finished[src] = true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i<=N;i++){
        if(discovered[i]==0){
            ret++;
            dfs(i,-1);
        }
    }
    
    cout<<ret-1;
}