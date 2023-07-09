#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int parent[10005];

struct e{
    int u,v,d;
};

int find(int u){
    if(parent[u] == u) 
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    parent[u] = v;
}
vector<e> edge;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 1;i<=N;i++)
        parent[i] = i;
    for(int i = 0;i<M;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(d == 1){
            merge(a,b);
        }else{
            edge.push_back({a,b,c});
        }
    }

    sort(edge.begin(),edge.end(),[](e& a,e& b){
        return a.d > b.d;
    });

    int answer = 0;
    for(e & ed : edge){
        int u = find(ed.u);
        int v = find(ed.v);

        if(u == v){
            answer += ed.d;
        }else{
            merge(ed.u,ed.v);
        }
    }
    cout<<answer;
}