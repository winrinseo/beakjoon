#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
int N,M;
double adj[205][205];
double dist[205][205];
double metome[205];
double solve(int num){
    double ret = 0;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            //자기 자신을 향하는 간선일 경우
            if(i==j&&metome[i]){
                ret = max(ret,dist[num][i]+metome[i]/2);
            }
            //직접 연결되어 있는 간선
            else if(adj[i][j]){
                //먼저 불붙은 정점이 혼자 태우는 시간
                double gap = abs(dist[num][i]-dist[num][j]);
                //해당 정점에 불이 옮겨붙는 시간
                double s = min(dist[num][i],dist[num][j]);
                //간선을 모두 태우는데 걸리는 시간
                double t = gap+(adj[i][j]-gap)/2;
                if(gap>=adj[i][j]) t = adj[i][j];
                ret = max(ret,s+t);
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i =0;i<205;i++){
        for(int j = 0;j<205;j++){
            dist[i][j] = INF;
            if(i==j) dist[i][j] = 0;
        }
    }
    for(int i =0;i<M;i++){
        int a,b;double c;cin>>a>>b>>c;
        if(a==b) metome[a] = max(metome[a],c);
        else{
            //두 정점을 연결한 간선 중 타는데 가장 오래걸리는 간선만을 저장
            adj[a][b] = adj[b][a] = max(adj[a][b],c);
            //불이 옮겨붙는 최소 시간을 계산하기위해 간선의 최소값만을 저장
            dist[a][b] = dist[b][a] = min(dist[a][b],c);
        }
    }
    for(int k = 1;k<=N;k++){
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=N;j++){
                if(dist[i][j] > dist[i][k]+dist[k][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    double answer = INF;
    //불붙일 정점
    for(int i = 1;i<=N;i++){
        answer = min(answer,solve(i));
    }
    cout<<fixed;
    cout.precision(1);
    cout<<answer;
}