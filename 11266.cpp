#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V,E;
vector<int> adj[10005];
vector<int> spanning[10005];
vector<int> cut;
bool finished[10005];
int dfsn[10005];
int num = 0;
int answer = 0;
int dfs(int src,bool root){
    dfsn[src] = ++num;
    int node = 0;
    int res = dfsn[src];
    for(int there : adj[src]){
        if(dfsn[there]==0){
            node++;
            int a = dfs(there,false);
            //자식 노드중 나 자신보다 더 높은 노드로 올라가지 못한다면 해당 정점은 단절점이다.
            if(!finished[src]&&!root&&a>=dfsn[src]){
                answer++;
                finished[src] = true;
                cut.push_back(src);
            }
            res = min(res,a);
        }
        else res = min(res,dfsn[there]);
        //교차간선은 제외
    }
    //루트노드일 경우 서브트리의 개수가 2개이상이면 단절점
    if(root&&node>=2){
        answer++;
        cut.push_back(src);
    }
    return res;
}
int main(){
    cin>>V>>E;
    for(int i = 0;i<E;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i<=V;i++)
        if(dfsn[i]==0) dfs(i,true);
    sort(cut.begin(),cut.end());
    cout<<answer<<'\n';
    for(int i : cut)
        cout<<i<<" ";
}