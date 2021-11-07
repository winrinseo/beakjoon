#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <tuple>
using namespace std;
int N,M;
int parent[1005];
pair<int,int> coord[1005];
//거리 , x , y
vector<tuple<double,int,int>> edge;
int find(int u){
    if(parent[u]==u)
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u , int v){
    u = find(u),v = find(v);
    if(u==v) return;
    parent[u] = v;
}
double getlength(pair<int,int>& a,pair<int,int>& b){
    double one = abs(a.first - b.first);
    double two = abs(a.second - b.second);
    double ret = (one*one)+(two*two);
    return sqrt(ret);
}
double getSpanning(){
    sort(edge.begin(),edge.end());
    double ret = 0;
    for(int i = 0;i<edge.size();i++){
        double dist = get<0>(edge[i]);
        int u = get<1>(edge[i]); int v = get<2>(edge[i]);
        if(find(u)==find(v))
            continue;
        merge(u,v);
        ret += dist;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 1;i<=N;i++) parent[i] = i;
    for(int i = 1;i<=N;i++){
        cin>>coord[i].first>>coord[i].second;
    }
    for(int i = 1;i<=N;i++){
        for(int j = j+1;j<=N;j++){
            //i,j끼리 간선을 이어줌
            edge.push_back({getlength(coord[i],coord[j]),i,j});
        }
    }
    //이미 연결된 간선은 가중치가 0
    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;
        edge.push_back({0,a,b});
    }
    double answer = getSpanning();
    printf("%0.2f",answer);
}