#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 405
#define INF 987654321
using namespace std;
int N,M;
int c[MAX][MAX],f[MAX][MAX];
vector<int> adj[MAX];
int main(){
    //src : 0 , sink : 401
    // 소 : 1~200 , 축사 : 201~400
    cin>>N>>M;
    //src
    int src = 0,sink = 401;
    for(int i = 1;i<=N;i++){
        c[src][i] = 1;
        adj[src].push_back(i);
        adj[i].push_back(src);
        int a; cin>>a;
        for(int j = 0;j<a;j++){
            int w;cin>>w;
            w += 200;
            c[i][w] = INF;
            adj[i].push_back(w);
            adj[w].push_back(i);
        }
    }
    for(int i = 201;i<=M+200;i++){
        c[i][sink] = 1;
        adj[i].push_back(sink);
        adj[sink].push_back(i);
    }
    int total = 0;
    while(1){
        queue<int> q;
        vector<int> prev(MAX,-1);
        q.push(src);
        prev[src] = src;
        while(!q.empty()&&prev[sink]==-1){
            int curr = q.front(); q.pop();
            
            for(int next : adj[curr]){

                if(c[curr][next] - f[curr][next]>0&&prev[next] == -1){
                    prev[next] = curr;
                    q.push(next);
                    if(next==sink) break;
                }
            }
        }
        //더 이상 증가 간선이 없을 경우
        if(prev[sink]==-1) break;
        int amount = INF;
        for(int i = sink;i!=src;i=prev[i]){
            amount = min(amount,c[prev[i]][i]-f[prev[i]][i]);
        }
        for(int i = sink;i!=src;i=prev[i]){
            f[prev[i]][i] += amount;
            f[i][prev[i]] -= amount;
        }
        total += amount;
    }
    cout<<total;

}