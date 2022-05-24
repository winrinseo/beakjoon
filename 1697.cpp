#include <iostream>
#include <queue>
using namespace std;
int N,K;
int dist[100005];
int d[2] = {-1,1};
int bfs(){
    queue<int> q;
    q.push(N);
    dist[N] = 0;

    while(!q.empty()){
        int cur = q.front();q.pop();
        if(cur==K) return dist[cur];
        for(int i = 0;i<2;i++){
            int nc = cur+(1*d[i]);
            if(nc<0||nc>=100005) continue;
            if(!dist[nc]){
                dist[nc] = dist[cur]+1;
                q.push(nc);
            }
        }
        int nc = (cur*2);
        if(nc<0||nc>=100005) continue;
        if(!dist[nc]){
                dist[nc] = dist[cur]+1;
                q.push(nc);
        }  
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    cout<<bfs();
}