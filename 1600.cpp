#include <iostream>
#include <queue>
using namespace std;
struct point{
    int r,c,k,cnt;
};
int K,N,M;
bool board[205][205];
bool visited[205][205][31];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int hd[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
int bfs(){
    visited[0][0][K] = 1;
    queue<point> q;
    q.push({0,0,K,0});

    while(!q.empty()){
        point cur = q.front();q.pop();
        if(board[cur.r][cur.c]==1) cout<<cur.r<<" "<<cur.c<<" "<<cur.cnt<<"\n";
        if(cur.r==(N-1)&&cur.c==(M-1)) return cur.cnt;
        for(int i = 0;i<4;i++){
            int nr = cur.r+d[i][0];
            int nc = cur.c+d[i][1];
            if(nr<0||nr>=N||nc<0||nc>=M)
                continue;
            if(visited[nr][nc][cur.k]||board[nr][nc]==1)
                continue;
            visited[nr][nc][cur.k] = 1;
            q.push({nr,nc,cur.k,cur.cnt+1});
        }
        for(int i = 0;i<8;i++){
            int nr = cur.r+hd[i][0];
            int nc = cur.c+hd[i][1];
            if(cur.k==0) break;
            if(nr<0||nr>=N||nc<0||nc>=M)
                continue;
            if(visited[nr][nc][cur.k-1]||board[nr][nc]==1)
                continue;
            visited[nr][nc][cur.k-1] = 1;
            q.push({nr,nc,cur.k-1,cur.cnt+1});
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>K>>M>>N;

    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
            cin>>board[i][j];
    cout<<bfs();
}