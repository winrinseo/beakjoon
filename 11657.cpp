#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321000
using namespace std;
int N,M;
bool srctodst[505] = {false};
//음수 사이클에 포함된 정점
bool neg_cycle[505] = {false};
vector<pair<int,int>> adj[505];
vector<long long> bell(){
    vector<long long> ret(505,INF);
    ret[1] = 0;
    srctodst[1] = true;
    bool relax = true;
    for(int it = 0; it < N; it++){
        relax = false;
        for(int curr = 1;curr<=N;curr++){
            for(auto next : adj[curr]){
                //시작점에서 도달 가능하다면
                if(srctodst[curr]==true) srctodst[next.first] = true;
                if(ret[next.first]>ret[curr]+next.second){
                    if(it==N-1) neg_cycle[next.first] = true;
                    relax = true;
                    ret[next.first] = ret[curr]+next.second;
                }
            }
        }
        if(!relax) break;
    }
    //음수사이클이 존재하며 시작점에서 도달 가능한 경우
    if(relax) {
        for(int i = 1;i<=N;i++){
            if(srctodst[i]&&neg_cycle[i])
                return vector<long long>();
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i =0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<long long> answer = bell();
    if(answer.empty()){
        cout<<-1<<"\n";
        return 0;
    } 
    for(int i = 2;i<=N;i++){
        if(!srctodst[i])
            cout<<-1<<"\n";
        else cout<<answer[i]<<"\n";
    }
}