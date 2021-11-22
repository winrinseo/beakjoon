#include <iostream>
#include <queue>
using namespace std;
int N;
int d[3][2] = {{0,1},{1,1},{1,0}};
struct Point{
    int r,c,dir;
};
int board[20][20];
int bfs(){
    queue<Point> q;
    int ret = 0;
    q.push({1,2,0});
    while(!q.empty()){
        Point curr = q.front(); q.pop();
        if(curr.r==N&&curr.c==N) ret++;
        for(int i = 0;i < 3;i++){
            int nr = curr.r + d[i][0];
            int nc = curr.c + d[i][1];
            //갈 수 없는 방향인 경우
            if(abs(curr.dir - i)==2)
                continue;
            //out of range
            if(nr<1||nr>N||nc<1||nc>N)
                continue;
            if(board[nr][nc]==1)
                continue;
            if(i==1&&(board[nr-1][nc]==1||board[nr][nc-1]==1))
                continue;
            q.push({nr,nc,i});
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cin>>board[i][j];
        }
    }
    cout<<bfs();
}