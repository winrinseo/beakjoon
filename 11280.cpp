#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N,M;
vector<int> adj[40005];
stack<int> s;
int num = 0;
int dfsn[40005];
int sccn[40005];
bool finished[40005];
int sn = 0;
int getScc(int curr){
    dfsn[curr] = ++num;
    s.push(curr);
    int res = dfsn[curr];

    for(int next : adj[curr]){
        if(dfsn[next]==0)
            res = min(res,getScc(next));
        //이미 발견되었지만 아직 scc에 속하지 않은 정점
        else if(!finished[next]) res = min(res,dfsn[next]);
    }
    //자식 노드 부터 가장 높이 올라갈 수 있는 정점이 자기 자신인 경우
    if(res == dfsn[curr]){
        while(1){
            int v = s.top(); s.pop();
            sccn[v] = sn;
            finished[v] = true;
            if(v==curr) break;
        }
        sn++;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        // idx*2 , not : idx*2+1
        int a,b; cin>>a>>b;
        int u = (-a) < 0 ? abs(a)*2+1 : abs(a)*2;
        int v = b < 0 ? abs(b)*2+1 : abs(b)*2;
        adj[u].push_back(v);
        //대우 명제
        u = a < 0 ? abs(a)*2+1 : abs(a)*2;
        v = (-b) < 0 ? abs(b)*2+1 : abs(b)*2;
        adj[v].push_back(u);
    }
    for(int i = 1;i<=N;i++){
        if(!finished[i*2])
            getScc(i*2);
        if(!finished[i*2+1])
            getScc(i*2+1);
    }
    for(int i = 1;i <= N; i++){
        //같은 강결합에 두 명제가 속할 경우 CNF를 true로 만들 수 없다
        if(sccn[i*2]==sccn[i*2+1]){
            cout<<0;
            return 0;
        }
    }
    cout<<1;
}