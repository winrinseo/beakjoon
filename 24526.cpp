#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
stack<int> s;
vector<int> adj[100005];
int dfsn[100005],sn[100005],sccs[100005];
bool finished[100005];
int num = 0 , SN = 1;
int indegree[100005];
int getscc(int src){
    dfsn[src] = ++num;
    s.push(src);
    int ret = dfsn[src];
    for(int next : adj[src]){
        if(dfsn[next]==0)
            ret = min(ret,getscc(next));
        else if(!finished[next])
            ret = min(ret,dfsn[next]);
    }

    if(ret == dfsn[src]){
        while(1){
            int c = s.top();s.pop();
            sn[c] = SN;
            sccs[SN]++;
            finished[c] = true;
            if(c==src) break;
        }
        SN++;
    }
    return ret;
}
vector<int> sadj[100005];
int visited[100005];
int answer = 0;
int solve(int src){
    int ret = 1;
    for(int next:sadj[src]){
        if(visited[next]==0)
            ret = min(ret,solve(next));
        else ret = min(ret,visited[next]);
    }
    if(sccs[src] > 1) ret = -1;
    if(ret==1) {
        answer++;
    }
    return visited[src] = ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i = 1;i<=N;i++)
        if(!dfsn[i])
            getscc(i);
    for(int i = 1;i <= N;i++){
        for(int next:adj[i])
            if(sn[i] != sn[next]){
                sadj[sn[i]].push_back(sn[next]);
                indegree[sn[next]]++;
            }
                
    }
    for(int i = 1;i<SN;i++){
        if(!indegree[i])
            solve(i);
    }
        
    cout<<answer;
}