#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX_N 55
#define INF 987654321
using namespace std;
int N;
vector<int> adj[MAX_N];
int c[MAX_N][MAX_N],f[MAX_N][MAX_N];
int getI(char a){
    if(a<='Z') return a-'A';
    return a-'a'+26;
}

int main(){
    cin>>N;
    for(int i = 0;i<N;i++){
        char a,b; cin>>a>>b;
        int w; cin>>w;
        int u = getI(a),v = getI(b);
        adj[u].push_back(v);
        //역방향 간선 추가
        adj[v].push_back(u);
        c[u][v] += w;
        c[v][u] += w;
    }
    int source = getI('A'),sink = getI('Z');
    int total = 0;
    while(1){
        queue<int> q;
        vector<int> prev(MAX_N,-1);
        prev[source] = source;
        q.push(source);
        while(!q.empty()&&prev[sink]==-1){
            int curr = q.front();q.pop();
            
            for(int next : adj[curr]){
                //잔여 용량이 0이상인 간선을 선택
                if(c[curr][next]-f[curr][next]>0&&prev[next]==-1){
                    prev[next] = curr;
                    q.push(next);
                }
            }

        }
        if(prev[sink]==-1) break;
        int amount = INF;
        for(int i = sink;i!=source;i=prev[i]){
            amount = min(amount,c[prev[i]][i]-f[prev[i]][i]);
        }
        for(int i = sink;i!=source;i=prev[i]){
            f[prev[i]][i] += amount;
            //역방향 간선에 음수만큼 추가
            f[i][prev[i]] -= amount;
        }
        total += amount;
    }
    cout<< total;
}