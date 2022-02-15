#include <iostream>

using namespace std;

int N,M;
int parent[100005];
int t[100005];
int find(int u){
    if(u==parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u,int v){
    u = find(u),v = find(v);
    if(u>v) swap(u,v);
    if(u==v) return;
    parent[u] = v;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<100005;i++) parent[i] = i;
    for(int i = 0;i<M;i++){
        int u,v;cin>>u>>v;
        merge(u,v);
    }
    int answer = 0;
    for(int i = 0;i<N;i++)
        cin>>t[i];
    
    for(int i = 0;i<N-1;i++){
        if(find(t[i])!=find(t[i+1])) answer++;
    }
    cout<<answer;
}