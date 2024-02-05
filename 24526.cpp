/* 강결합으로 그래프 압축
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

*/

//강결합 없는  풀이

#include <iostream>
#include <vector>

using namespace std;

int N,M;
//방문을 표시할 배열
//함수의 종료 여부 , 해당 정점이 사이클에 속해있는지
bool visited[100005],notFinished[100005], isCycle[100005];

vector<int> adj[100005];
int answer = 0;
int dfs(int cur){
    notFinished[cur] = true;
    visited[cur] = true;
    // cout<<cur<<" ";
    int ret = 1;
    for(int & next : adj[cur]){
        //종료되지 않은 정점에 연결된 것은 사이클에 속해있다는거임
        //참조하는 정점이 이미 사이클에 속해있으면 해당 정점도 예외임
        if(notFinished[next] || isCycle[next]){
            ret = -1;
            isCycle[cur] = true;
        } else if(!visited[next]){
            ret = min(ret , dfs(next));
        }
    }
    
    if(ret == 1){
        // cout<<cur<<" ";
        answer++;
    }else{
        isCycle[cur] = true;
    }
    notFinished[cur] = false;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;

        adj[a].push_back(b);
    }

    for(int i = 1;i<=N;i++){
        // cout<<i%N;
        if(visited[i]) continue;
        dfs(i);
    }

    cout<<answer;
}