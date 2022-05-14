#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int N;
ll WS[123459];
vector<int> adj[123459];
ll dfs(int cur,int p){
    ll& ret = WS[cur];

    for(int& next : adj[cur]){
        if(next!=p){
            ret += dfs(next,cur);
        }
    }
    if(ret < 0) ret = 0;
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 2;i<=N;i++){
        char a;int s, t;
        cin>>a>>s>>t;
        if(a=='W'){
            WS[i] = -s;
            adj[t].push_back(i);
            adj[i].push_back(t);
        }else{
            WS[i] = s;
            adj[t].push_back(i);
            adj[i].push_back(t);
        }
    }
    cout<<dfs(1,0);
}