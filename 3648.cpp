#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int N,M;
vector<int> adj[4005];
stack<int> s;
int dfsn[4005];
bool finished[4005];
int sccn[4005];
int num,sn;
int getScc(int curr){
    dfsn[curr] = ++num;
    s.push(curr);
    int res = dfsn[curr];

    for(int next : adj[curr]){
        if(dfsn[next] == 0){
            res = min(res,getScc(next));
        }else if(!finished[next])
            res = min(res,dfsn[next]);
    }

    if(res == dfsn[curr]){
        while(1){
            int t = s.top(); s.pop();
            sccn[t] = sn;
            finished[t] = true;
            if(t==curr) break;
        }
        sn++;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>N>>M;
        if(cin.eof()) break;
        for(int i = 0;i<4005;i++) adj[i].clear();
        fill(dfsn,dfsn+4005,0);
        fill(finished,finished+4005,0);
        fill(sccn,sccn+4005,-1);
        s = stack<int>();
        num = sn = 0;

        for(int i = 0;i<M;i++){
            int a,b; cin>>a>>b;
            int u = (-a) < 0 ? abs(a)*2+1 : abs(a)*2;
            int v = b < 0 ? abs(b)*2+1 : abs(b)*2;
            adj[u].push_back(v);

            u = a < 0 ? abs(a)*2+1 : abs(a)*2;
            v = (-b) < 0 ? abs(b)*2+1 : abs(b)*2;
            adj[v].push_back(u);
        }

        //1번 참가자는 무조건 참이 되어야 한다.
        //(1 | 1) 절 추가
        adj[1*2+1].push_back(1*2); // ~1 -> 1

        for(int i = 1;i<=N;i++){
            if(!finished[i*2]) getScc(i*2);
            if(!finished[i*2+1]) getScc(i*2+1);
        }
        bool flag = true;
        for(int i = 1;i<=N;i++){
            //같은 변수가 같은 강결합에 속해있는 경우 모순
            if(sccn[i*2]==sccn[i*2+1]){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
    }
    
}