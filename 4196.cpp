#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>
#include <vector>

using namespace std;
int T,N,M;
vector<int> adj[100005];
bool finished[100005];
int dfsn[100005];
int sccN[100005];
stack<int> s;
int num ,SN;
int getScc(int src){
    dfsn[src] = ++num;
    s.push(src);
    int result = dfsn[src];

    for(int there : adj[src]){
        if(dfsn[there]==0) result = min(result,getScc(there));
        else if(!finished[there]) result = min(result , dfsn[there]);
    }

    if(result == dfsn[src]){
        while(1){
            int t = s.top();s.pop();
            sccN[t] = SN;
            finished[t] = true;
            if(t==src) break;
        }
        SN++;
    }
    return result;
}
int main(){
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i = 1;i<=N;i++) adj[i].clear();
        num = SN = 0;
        memset(finished,0,sizeof(finished));
        memset(dfsn,0,sizeof(dfsn));
        memset(sccN,0,sizeof(sccN));
        for(int i = 0;i < M; i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        for(int i = 1;i<=N;i++) if(dfsn[i]==0) getScc(i);
        int sccIndegree[100005] = {0};
        for(int i =1;i<=N;i++){
            for(int j : adj[i]){
                if(sccN[i]!=sccN[j]){
                    sccIndegree[sccN[j]]++;
                }
            }
        }
        int answer = 0;
        for(int i = 0;i<SN;i++){
            if(sccIndegree[i]==0)
                answer++;
        }
        cout<<answer<<'\n';
    }
}