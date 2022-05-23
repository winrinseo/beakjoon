#include <iostream>
#define INF 987654321
using namespace std;
int N,M;
int dist[105][105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<105;i++)
        for(int j=0;j<105;j++)
            if(i!=j) dist[i][j] = INF;

    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;
        dist[a][b] = dist[b][a] = 1;
    }
    for(int k = 1;k<=N;k++)
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=N;j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    int a = INF;
    int answer = 0;     
    for(int i = 1;i<=N;i++){
        int sum = 0;
        for(int j = 1;j<=N;j++)
            if(dist[i][j]!=INF)
                sum+=dist[i][j];
        if(a>sum) {
            a=sum;
            answer = i;
        }
    }
    cout<<answer;    
}