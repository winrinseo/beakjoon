#include <iostream>
#include <vector>
using namespace std;

int N , M;
vector<int> adj[505];
bool visited[505];

int dfs(int cur , int p){
    visited[cur] = true;
    
    int ret = 1;

    for(int & next : adj[cur]){
        
        if(next == p) continue;
        if(visited[next])
            ret = 0;   
        else ret = min(ret , dfs(next,cur));
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while(1){
        cin>>N;  
        for(int i = 0;i<505;i++){
            adj[i].clear();
            visited[i] = 0;
        }
        
        cin>>M;

        if(N == 0 && M == 0) break;

        for(int i = 0;i<M;i++){
            int a,b;
            cin>>a>>b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int answer = 0;

        for(int i = 1;i<=N;i++){
            if(!visited[i])
                answer += dfs(i , -1);
        }
        cout<<"Case "<<T++<<": ";
        if(answer == 0){
            cout<<"No trees.";
        }else if(answer == 1){
            cout<<"There is one tree.";
        }else {
            cout<<"A forest of "<<answer<<" trees.";
        }
        cout<<"\n";
        
    }  

}