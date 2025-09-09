#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct e{
    int s,e,d;
};
int N;
vector<e> edge;

int parent[1005];

int find(int u){
    if(parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u , int v){
    u = find(u);
    v = find(v);

    if(u == v) return;

    parent[u] = v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<1005;i++) parent[i] = i;

    for(int i = 0;i<N;i++){
        int d;

        for(int j = 0;j<N;j++){
            cin>>d;
            if(i == j) continue;
            edge.push_back({i,j,d});
        }
    }

    sort(edge.begin(),edge.end() , [](e & a, e & b){
        return a.d < b.d;
    });

    long long answer = 0;
    for(int i = 0;i<edge.size();i++){

        int u = find(edge[i].s);
        int v = find(edge[i].e);

        if(u != v){
            answer += edge[i].d;
            merge(edge[i].s , edge[i].e);
        }
    }

    cout<<answer;
    
}