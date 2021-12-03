#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
vector<int> adj[5050];
int getCol(int c){
    return (N*2+1)+(c*2);
}

int dfsn[5050],sccn[5050];
bool finished[5050];
stack<int> s;
int num , sn = 1;

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
            if(t==curr) break;
        }
        sn++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            char a; cin>>a;
            if(a=='#'){
                //위치추적기의 경우 해당 행과 열을 모두 밟거나 밟지 않아야한다.
                adj[i*2].push_back(getCol(j));
                adj[getCol(j)+1].push_back(i*2+1);

                adj[i*2+1].push_back(getCol(j)+1);
                adj[getCol(j)].push_back(i*2);
            }
            if(a=='*'){
                //보석의 경우 행과 열 둘중 하나는 반드시 밟아야한다.
                adj[i*2+1].push_back(getCol(j));
                adj[getCol(j)+1].push_back(i*2);

                adj[i*2].push_back(getCol(j)+1);
                adj[getCol(j)].push_back(i*2+1);
            }
        }
    }
    int end = (N*2+1) + (M*2+1);
    for(int i = 1;i<=end;i++){
        if(dfsn[i]==0) getScc(i);
    }

    for(int i = 1;i<=N;i++){
        if(sccn[i*2]==sccn[i*2+1]){
            cout<<0;
            return 0;
        }
    }
    for(int i = 1;i<=M;i++){
        if(sccn[getCol(i)]==sccn[getCol(i)+1]){
            cout<<0;
            return 0;
        }
    }
    cout<<1;
}