#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> adj[100005];

int p[100005];

void dfs(int cur , int sum){
    
    for(int & next : adj[cur])
        dfs(next , sum + p[cur]);
    
    p[cur] += sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 1;i<=N;i++){
        int a;cin>>a;
        if(a != -1)
            adj[a].push_back(i);
    }

    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;

        p[a] += b;
    }

    dfs(1,0);

    for(int i = 1;i<=N;i++)
        cout<<p[i]<<" ";
}