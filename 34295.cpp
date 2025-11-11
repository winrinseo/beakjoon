#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;
struct Point{
    int x,y;
    int up; // 고도가 올랐는지.
};
int N,M;
int p[505][505];
int visited[505][505][2];
pii from, to;
int d[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int bfs(){
    queue<Point> q;

    q.push({from.first,from.second,0});
    visited[from.first][from.second][0] = 1;
    q.push({from.first,from.second,1});
    visited[from.first][from.second][1] = 1;

    while(!q.empty()){
        Point cur = q.front();q.pop();
        if(cur.x == to.first && cur.y == to.second)
            return visited[cur.x][cur.y][cur.up] - 1;

        for(int i = 0;i<8;i++){
            int nx = cur.x + d[i][0];
            int ny = cur.y + d[i][1];
            int na = (cur.up + 1) % 2;
            if(nx < 1 || nx > N || ny < 1 || ny > M)
                continue;
            
            if(visited[nx][ny][na] == 0){
                if((na == 0 && p[cur.x][cur.y] > p[nx][ny]) || 
                        (na == 1 && p[cur.x][cur.y] < p[nx][ny])){
                    q.push({nx,ny,na});
                    visited[nx][ny][na] = visited[cur.x][cur.y][cur.up] + 1;
                }
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 1;i<=N;i++ )
        for(int j = 1;j<=M;j++)
            cin>>p[i][j];

    cin>>from.first>>from.second;
    cin>>to.first>>to.second;

    cout<<bfs();
}