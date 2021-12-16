#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
int parent[205];
bool adj[205][205];
vector<int> order;
int find(int u){
    if(parent[u]==u)
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u,int v){
    u = find(u); v = find(v);
    if(u==v) return;
    parent[u] = v;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<205;i++) parent[i] = i;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cin>>adj[i][j];
        }
    }
    for(int i = 0;i<M;i++){
        int a;cin>>a;
        order.push_back(a);
    }

    for(int k = 1;k<=N;k++)
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=N;j++)
                if(adj[i][k]&&adj[k][j]){
                    adj[i][j] = true;
                    merge(i,j);
                }
            
    if(order.empty()){
        cout<<"YES";
        return 0;
    }   
    int a = find(order[0]);
    for(int i = 1;i<order.size();i++){
        if(a!=find(order[i])){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}