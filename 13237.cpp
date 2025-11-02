#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> adj[25];
int depth[25];

void dfs(int cur , int d){
    depth[cur] = d;

    for(int & next : adj[cur]){
        dfs(next , d+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int root;
    for(int i = 1;i<=N;i++){
        int a;cin>>a;
        if(a != -1){
            adj[a].push_back(i);
        }else{
            root = i;
        }
    }

    dfs(root , 0);

    for(int i = 1;i<=N;i++)
        cout<<depth[i]<<"\n";
}