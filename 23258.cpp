#include <iostream>
#include <string>
#include <algorithm>
#define INF 987654321
using namespace std;
int N,Q;
int adj[305][305][305];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cin>>adj[i][j][0];
            if(adj[i][j][0]==0&&i!=j)
                adj[i][j][0] = INF;
        }
    }
    for(int k = 1;k<=N;k++)
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=N;j++)
                adj[i][j][k] = min(adj[i][j][k-1],adj[i][k][k-1]+adj[k][j][k-1]);

    for(int i =0;i<Q;i++){
        int c,s,e;cin>>c>>s>>e;
        int answer = adj[s][e][c-1];
        if(answer==INF) cout<<-1<<"\n";
        else cout<<answer<<"\n";
    }
}