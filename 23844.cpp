#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> t[10005];
//depth에서 가장 적은 자식을 가진 노드
priority_queue<pair<int,int>> pq[10005];
int dep[10005],ntod[10005];
bool isdel[10005];
int N,K;
int pre_dfs(int curr,int depth){
    int ret = 0;
    dep[depth]++;
    ntod[curr] = depth;
    for(int& next : t[curr]){
        if(ntod[next]==-1)
            ret += pre_dfs(next,depth+1);
    }
    pq[depth].push({-ret,curr});
    return (ret+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    fill(ntod,ntod+10005,-1);
    pre_dfs(1,0);
    int answer = 0;
    for(int d = 0;d < 10005;d++){
        if(dep[d]==0) break;
        
        if(dep[d] > K){
            answer+=K;
        }else{
            answer+=dep[d];
        }
        
    }
    cout<<answer;
}