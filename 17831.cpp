#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
int N;
vector<int> adj[200005];
//dp 1 : 자식 노드와 멘토링 관계를 맺었을 때
int p[200005],dp[200005][2];
void dfs(int cur){
    
    int maxgap = -INF;

    for(int& next : adj[cur]){
        dfs(next);
        dp[cur][0] += max(dp[next][0],dp[next][1]);
        //dp[cur][1]을 계산하기 위해 서브트리의 최대값과 자식노드와 멘토를 맺었을 때의 점수 차를 계산함
        maxgap = max(maxgap,(dp[next][0]+p[next]*p[cur]) - max(dp[next][0],dp[next][1]));
    }
    dp[cur][1] = dp[cur][0] + maxgap;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for(int i = 2;i<=N;i++){
        int a;cin>>a;
        adj[a].push_back(i);
    }
    for(int i = 1;i<=N;i++)
        cin>>p[i];
    dfs(1);
    cout<<max(dp[1][1],dp[1][0]);
}