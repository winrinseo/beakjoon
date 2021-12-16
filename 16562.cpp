#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,K;
int parent[10005];
vector<pair<int,pair<int,int>>> path;
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
    cin>>N>>M>>K;
    for(int i = 1;i<=N;i++){
        int a;cin>>a;
        path.push_back({a,{0,i}});
    }
    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;
        path.push_back({0,{a,b}});
    }
    for(int i = 0;i<10005;i++) parent[i] = i;
    sort(path.begin(),path.end());
    int answer = 0;
    for(int i =0;i<path.size();i++){
        int p = path[i].first;
        int u = path[i].second.first, v = path[i].second.second;
        if(find(u)==find(v)) continue;
        merge(u,v);
        answer+=p;
    }
    if(K>=answer) cout<<answer;
    else cout<<"Oh no";
}