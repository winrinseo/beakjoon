#include <iostream>
#include <queue>
using namespace std;
struct Point{
    int r,c,t;
};
int N = 8;
char board[8][8][10];
bool visited[8][8][10];
int d[9][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};
bool bfs(){
    queue<Point> q;
    visited[N-1][0][0] = true;
    q.push({N-1,0,0});

    while(!q.empty()){
        Point cur = q.front();q.pop();
        if(cur.r==0&&cur.c==N-1) return 1;
        if(board[cur.r][cur.c][cur.t]=='#')
            continue;
        for(int i = 0;i < 9;i++){
            int nr = cur.r+d[i][0];
            int nc = cur.c+d[i][1];
            int nt = cur.t+1;
            
            if(nt >= 8) nt = 8;
            if(nr>=8||nr<0||nc>=8||nc<0)
                continue; 
            if(visited[nr][nc][nt])
                continue;
            if(board[nr][nc][cur.t]=='#'||board[nr][nc][nt]=='#')
                continue;
            visited[nr][nc][nt] = true;
            q.push({nr,nc,nt});
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            cin>>board[i][j][0];
            for(int k = 1;k < 8;k++){
                if(i+k>=8) break;
                board[i+k][j][k] = board[i][j][0];
            }
        }
    }
    cout<<bfs();
}