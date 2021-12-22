#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#define INF 1e9
using namespace std;
int N,K;
int M;
pair<int,int> V[100005];
int pre[100005];
int dist[100005];
int b_search(int target){
    int lo = 0,hi = N;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(V[mid].first==target) return mid;
        if(V[mid].first>target){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    return -1;
}
void bfs(int src){
    priority_queue<pair<int,int>> pq;
    fill(pre+1,pre+N+1,-1);
    fill(dist+1,dist+N+1,INF);
    int s = b_search(src);
    pq.push({0,s});
    dist[1] = 0;
    while(!pq.empty()){
        int hd = -pq.top().first;
        int cidx = pq.top().second;
        pq.pop();
        for(int i = K-1;i>=0;i--){
            int next = V[cidx].first^(1<<i);
            int nidx = b_search(next);
            if(nidx==-1) continue;
            if(dist[V[nidx].second] > hd+1){
                dist[V[nidx].second] = hd+1;
                pre[V[nidx].second] = V[cidx].second;
                pq.push({-(hd+1),nidx});
            }
        }    
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    int src;
    for(int i=0;i<N;i++){
        int w = 0;
        for(int j = K-1;j>=0;j--){
            char a;cin>>a;
            if(a=='1'){
                w |= (1<<j);
            }
        }
        V[i] = {w,i+1};
        if(!i) src = w;
    }
    sort(V,V+N);
    bfs(src);
    cin>>M;
    for(int i = 0;i<M;i++){
        int dst;cin>>dst;
        vector<int> path;
        if(pre[dst]==-1){
            cout<<-1<<"\n";
            continue;
        }
        for(int a = dst;a!=-1;a = pre[a]){
            path.push_back(a);
        }
        for(int a = path.size()-1;a>=0;a--){
            cout<<path[a]<<" ";
        }
        cout<<"\n";
    }
}