#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
using ll = long long;
int N,M;
//목적지 , 주기
vector<pair<int,int>> adj[100005];
ll dist[100005];
//현재 시간과 건널 간선이 주어졌을 때 건널 수 있는 최소의 시간을 반환
ll get_distance(ll time,int num){
    int coef = time/M;
    if(time <= ((ll)M*coef+num)) return ((ll)M*coef+num);
    return ((ll)M*(coef+1)+num);
}
ll dij(){
    priority_queue<pair<ll,int>> pq;
    fill(dist,dist+100005,INT64_MAX);
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()){
        int curr = pq.top().second;
        ll hd = -pq.top().first;
        pq.pop();
        if(curr == N) return hd;
        for(int i =0;i < adj[curr].size();i++){
            int next = adj[curr][i].first;
            int cycle = adj[curr][i].second;
            ll able_to_cross = get_distance(hd,cycle);
            if(dist[next] > able_to_cross+1){
                dist[next] = able_to_cross+1;
                pq.push({-(able_to_cross+1),next});
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i < M;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    cout<<dij();
}