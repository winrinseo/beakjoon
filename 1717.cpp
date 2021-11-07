#include <iostream>
using namespace std;
int N,M;
int parent[1000005];
int find(int u){
    if(parent[u]==u)
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u,int v){
    u = find(u), v = find(v);
    if(u==v) return;
    parent[u] = v;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i =1;i<=N;i++) parent[i] = i;
    for(int i = 0;i<M;i++){
        int c,a,b; cin>>c>>a>>b;
        if(c==0){
            merge(a,b);
        }else{
            if(find(a)==find(b))
                cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
}