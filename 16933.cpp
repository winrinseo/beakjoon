#include <iostream>
#include <queue>
using namespace std;
int N,M,K;
char board[1005][1005];
bool visited[1005][1005][11][2];
int d[5][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
struct Point{
    int r,c,d;
    int state,k;
};
int bfs(){
    queue<Point> q;
    //낮 : 1 , 밤: -1
    q.push({0,0,1,1,K});
    visited[0][0][K][1] = true;
    while(!q.empty()){
        Point curr = q.front(); q.pop();
        if(curr.r==(N-1)&&curr.c==(M-1)) return curr.d;
        for(int i = 0;i < 5;i++){
            int nr = curr.r+d[i][0];
            int nc = curr.c+d[i][1];
            int ns = -curr.state, nsidx = ns > 0? 0:1;
            int nd = curr.d+1;
            if(nr<0||nr>=N||nc<0||nc>=M)
                continue;
            if(visited[nr][nc][curr.k][nsidx])
                continue;
            if(i!=0&&board[nr][nc]=='1'){
                if(curr.k > 0 && curr.state > 0){
                    visited[nr][nc][curr.k][nsidx] = true;
                    q.push({nr,nc,nd,ns,curr.k-1});
                }else continue;
            }else{
                visited[nr][nc][curr.k][nsidx] = true;
                q.push({nr,nc,nd,ns,curr.k});
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin>>board[i][j];

    cout<<bfs();
}