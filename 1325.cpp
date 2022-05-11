#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> adj[10005];
bool visited[10005];
int dfs(int cur){
    visited[cur] = true;
    int ret = 1;
    for(int& next : adj[cur])
        if(!visited[next])
            ret += dfs(next);
    
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;
        adj[b].push_back(a);
    }
    int s = 0;
    vector<int> answer;
    for(int i = 1;i<=N;i++){
        fill(visited,visited+10005,0);
        int a = dfs(i);
        if(a > s){
            s = a;
            answer.clear();
            answer.push_back(i);
        }else if(a==s){
            answer.push_back(i);
        }

    }
    sort(answer.begin(),answer.end());
    for(int i = 0;i<answer.size();i++)
        cout<<answer[i]<<" ";
}