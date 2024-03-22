#include <iostream>
#include <algorithm>
using namespace std;
struct edge {
    int d;
    int s,e;
};
int N,M;
int s[1005] ,  p[1005];
edge e[10005];

int find(int u){
    if(u == p[u])
        return u;
    return p[u] = find(p[u]);
}

void merge(int u , int v){
    u = find(u); v = find(v);
    if(u == v)
        return;
    p[u] = v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 1;i<=N;i++){
        char a; cin>>a;
        s[i] = (a == 'M');
        p[i] = i;
    }

    for(int i = 0;i<M;i++){
        int u,v,d;
        cin>>u>>v>>d;

        e[i] = {d , u , v};
    }

    sort(e , e + M , [](edge & a , edge & b){
        return a.d < b.d;
    });

    int answer = 0;
    for(int i = 0;i<M;i++){
        int u = e[i].s;
        int v = e[i].e;

        if(find(u) != find(v) && s[u] != s[v]){
            answer += e[i].d;
            merge(u,v);
        }
    }

    for(int i = 2; i <= N; i++){
        if(find(i-1) != find(i)){
            cout<<-1;
            return 0;
        }
    }
    cout<<answer;
}