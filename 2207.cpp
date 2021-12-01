#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int N,M;
vector<int> adj[20500];
stack<int> s;
int dfsn[20500];
int sccn[20500];
bool finished[20500];
int num,sn;
int getScc(int curr){
    dfsn[curr] = ++num;
    s.push(curr);
    int res = dfsn[curr];

    for(int next : adj[curr]){
        if(dfsn[next]==0)
            res = min(res,getScc(next));
        else if(!finished[next])
            res = min(res,dfsn[next]);
    }

    if(res == dfsn[curr]){
        while(1){
            int t = s.top(); s.pop();
            sccn[t] = sn;
            finished[t] = true;
            if(t == curr) break;
        }
        sn++;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<N;i++){
        int a,b; cin>>a>>b;
        int u = (-a) < 0 ? abs(a)*2+1:abs(a)*2;
        int v = b < 0 ? abs(b)*2+1:abs(b)*2;
        adj[u].push_back(v);

        u = a < 0 ? abs(a)*2+1:abs(a)*2;
        v = (-b) < 0 ? abs(b)*2+1:abs(b)*2;
        adj[v].push_back(u);
    }
    for(int i = 1;i<=M;i++){
        if(!finished[i*2]) getScc(i*2);
        if(!finished[i*2+1]) getScc(i*2+1);
    }
    for(int i = 1;i<=M;i++){
        if(sccn[i*2]==sccn[i*2+1]){
            cout<<"OTL";
            return 0;
        }
    }
    cout<<"^_^";
}