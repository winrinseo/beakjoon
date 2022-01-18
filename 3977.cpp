#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int N,M;
vector<int> adj[100005];

int dfsn[100005];
bool finished[100005];
stack<int> s;
//n번 노드가 속한 강결합
int scc[100005];
//n번 강결합의 멤버
vector<vector<int>> sccm;
//강결합의 진입차수
int indegree[100005];
int num,sccN;
int getscc(int src){
    dfsn[src] = ++num;
    s.push(src);
    int ret = dfsn[src];
    for(int next : adj[src]){
        if(dfsn[next]==0) ret = min(ret,getscc(next));
        else if(!finished[next]) ret = min(ret,dfsn[next]);
    }

    if(ret == dfsn[src]){
        vector<int> sccc;
        while(1){
            int t = s.top();s.pop();
            scc[t] = sccN;
            sccc.push_back(t);
            finished[t] = true;
            if(t==src) break;
        }
        sccm.push_back(sccc);
        sccN++;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    
    while(T--){
        num = 0,sccN = 0;
        sccm.clear();
        for(int i = 0;i<100005;i++) {
            adj[i].clear();
            scc[i] = 0;
            finished[i] = 0;
            indegree[i] = 0;
            dfsn[i] = 0;
        }
        while(!s.empty()) s.pop();
        cin>>N>>M;
        for(int i = 0;i<M;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        
        for(int i = 0;i<N;i++)
            if(dfsn[i]==0) getscc(i);
        
        for(int i = 0;i<N;i++){
            for(int next : adj[i]){
                if(scc[i]!=scc[next])
                    indegree[scc[next]]++;
            }
        }
        //진입차수가 0인 강결합을 찾아줌
        int answer = -1;bool flag =false;
        for(int i = 0;i<sccN;i++){
            if(indegree[i]==0){
                if(answer==-1){
                    answer = i;
                }
                else flag = true;
                
            }
        }
        if(!flag){
            sort(sccm[answer].begin(),sccm[answer].end());
            for(int as:sccm[answer]) cout<<as<<"\n";
        }else cout<<"Confused"<<"\n";
        cout<<"\n";
    }   
}