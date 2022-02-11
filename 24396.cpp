#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int N,M;
int dist[300005];
bool visited[300005];
set<int> cut[300005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    
    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;
        cut[a].insert(b);
        cut[b].insert(a);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    vector<int> nxt;
    for(int i = 1;i<=N;i++)
        nxt.push_back(i);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        vector<int> r;
        for(int i = 0;i<nxt.size();i++){
            if(visited[nxt[i]]) 
                continue;
            else if(cut[curr].count(nxt[i])){
                r.push_back(nxt[i]);
            }else{
                visited[nxt[i]] = true;
                dist[nxt[i]] = dist[curr]+1;
                q.push(nxt[i]);
            }
        }
        nxt = r;
    }
    cout<<0<<"\n";
    for(int i = 2;i<=N;i++)
        if(dist[i]==0) cout<<-1<<"\n";
        else cout<<dist[i]<<"\n";
}