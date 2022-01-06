#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 20
using namespace std;
int N,M;
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int dp[25][1<<MAX];
char board[1020][1020];
bool vis[1020][1020];
int dist[25][25];
pair<int,int> src[25];//1 : 출발지 , 2 ~ : 식당번호
int cton[1020][1020];
int idx = 1;
struct Point{
    int d,r,c;
};
void bfs(int num){
    //거리,위치
    queue<Point> q;
    q.push({0,src[num].first,src[num].second});
    vis[src[num].first][src[num].second] = true;
    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int hd = q.front().d;
        q.pop();
        if(cton[r][c]){
            dist[num][cton[r][c]] = hd;
            dist[cton[r][c]][num] = hd; 
        }
        for(int i = 0;i<4;i++){
            int nr = r+d[i][0];
            int nc = c+d[i][1];
            if(nr>=N||nr<0||nc>=M||nc<0)
                continue;
            if(board[nr][nc]=='X'||vis[nr][nc])
                continue;
            vis[nr][nc] = true;
            q.push({hd+1,nr,nc});
        }
    }
    return;
}
int answer = INF;
bool visited[25];
void solve(int cur,int k,int d){
    if(k==5) {
        answer = min(answer,d);
        return;
    }
    for(int i = 1;i<=idx;i++){
        if(visited[i]||dist[cur][i]==INF)
            continue;
        visited[i] = true;
        solve(i,k+1,d+dist[cur][i]);
        visited[i] = false;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<N;i++){
        for(int j =0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]=='S'){
                src[1] = {i,j};
                cton[i][j] = 1;
            }else if(board[i][j]=='K'){
                src[++idx] = {i,j};
                cton[i][j] = idx;
            }
        }
    }
    //식당의 개수 idx
    if(idx-1 < 5){
        cout<<-1;
        return 0;
    }
    for(int i =0;i<25;i++)
        for(int j =0;j<25;j++) dist[i][j] = INF;
    for(int i = 1;i<=idx;i++){
        memset(vis,0,sizeof(vis));
        bfs(i);
    }
    visited[1] = true;
    solve(1,0,0);
    if(answer==INF) cout<<-1;
    else cout<<answer;
}