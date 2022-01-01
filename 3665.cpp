#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
bool adj[505][505];
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        int n;cin>>n;
        memset(adj,0,sizeof(adj));
        int indegree[505] = {0};
        int v[505] = {0};
        int p[505] = {0};
        int num[505] = {0};
        for(int i =0;i<n;i++){
            cin>>v[i];
            num[v[i]] = i;
            
        }
        for(int i =0;i<n-1;i++){
            for(int j = i+1;j<n;j++) {
                adj[v[i]][v[j]] = 1;
                //p[v[i]] = v[i-1];
                indegree[v[j]]++;
            }
        }
        int m;cin>>m;
        for(int i = 0;i<m;i++){
            int a,b;cin>>a>>b;
            if(num[a] < num[b]) swap(a,b);
            adj[a][b] = 1;
            adj[b][a] = 0;
            indegree[a]--;
            indegree[b]++;
        }
        queue<int> q;
        for(int i =1;i<=n;i++){
            if(indegree[i]==0) q.push(i);
        }
        bool flag = true;
        int result[505] = {0};
        for(int i = 0;i<n;i++){
            if(q.empty()){
                cout<<"IMPOSSIBLE"<<"\n";
                flag = false;
                break;
            }
            int curr = q.front(); q.pop();
            result[i] = curr;
            for(int i =1;i<=n;i++){
                if(adj[curr][i]){
                    if(--indegree[i]==0) q.push(i);
                    adj[curr][i] = 0;
                }
            }
        }
        if(flag){
            for(int i =0;i<n;i++){
                cout<<result[i]<<" ";
            }
            cout<<"\n";
        }
    }
}