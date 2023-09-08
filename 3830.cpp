#include <iostream>
using namespace std;

int N,M;
int parent[100005],pd[100005];

int find(int u){
    if(parent[u] == u) 
        return u;
    int pp = parent[u];
    parent[u] = find(parent[u]);
    pd[u] = pd[pp] + pd[u];
    return parent[u];
}
void merge(int u,int v , int d){
    int uu = find(u);
    int vv = find(v);

    if(uu == vv) return;

    parent[uu] = vv;
    parent[u] = v;
    pd[uu] = (pd[v]+d) - pd[u];
    pd[u] = d;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin>>N>>M;
        if(N == 0 && M == 0) 
            return 0;
        
        for(int i = 1;i<=N;i++){
            parent[i] = i;
            pd[i] = 0;
        }

        for(int i = 0;i<M;i++){
            char cmd;
            int a,b,c;
            cin>>cmd;

            if(cmd == '!'){
                cin>>a>>b>>c;
                merge(a,b,c);
            }else{
                cin>>a>>b;
                int u = find(a);
                int v = find(b);
                if(u!=v){
                    cout<<"UNKNOWN"<<"\n";
                }else{
                    cout<<pd[a] - pd[b]<<"\n";
                }
            }
        }
    }
}