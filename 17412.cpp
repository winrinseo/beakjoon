#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 987654321
#define MAX 405
using namespace std;
int N,P;
vector<int> adj[MAX];
int c[MAX][MAX],f[MAX][MAX];
int main(){
    cin>>N>>P;
    for(int i =0;i<P;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        c[a][b] = 1;
    }
    int src = 1,sink = 2;
    int total = 0;
    while(1){
        queue<int> q;
        vector<int> prev(MAX,-1);
        prev[src] = src;
        q.push(src);
        while(!q.empty()&&prev[sink]==-1){
            int curr = q.front(); q.pop();

            for(int next : adj[curr]){

                if(c[curr][next]-f[curr][next]>0&&prev[next]==-1){
                    prev[next] = curr;
                    q.push(next);
                }
            }
        }
        if(prev[sink]==-1) break;

        int amount = INF;
        for(int i = sink; i!=src;i=prev[i]){
            amount = min(amount,c[prev[i]][i]-f[prev[i]][i]);
        }
        for(int i = sink; i!=src;i=prev[i]){
            f[prev[i]][i] += amount;
            f[i][prev[i]] -= amount;
        }
        total += amount;
    }
    cout<<total;
}