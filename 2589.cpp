#include <iostream>
#include <queue>
#define INF 987654321
#define pii pair<int,int>
using namespace std;
int N,M;
int dist[55][55][55][55];
char board[55][55];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
void bfs(int r,int c){
    queue<pii> q;
    q.push({r,c});

    while(!q.empty()){
        int hr = q.front().first;
        int hc = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nr = hr+d[i][0];
            int nc = hc+d[i][1];
            if(nr<0||nr>=N||nc<0||nc>=M)
                continue;
            if(board[nr][nc]=='W')
                continue;
            if(dist[r][c][nr][nc]==0){
                dist[r][c][nr][nc] = dist[r][c][hr][hc]+1;
                q.push({nr,nc});
            }
        }
    }
    dist[r][c][r][c] = 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
            cin>>board[i][j];
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(board[i][j]=='L')
                bfs(i,j);
        }
    }
    int answer = 0;
    for(int a = 0;a<N;a++)
        for(int b = 0;b<M;b++)
            for(int c = 0;c<N;c++)
                for(int d = 0;d<M;d++){
                    answer = max(answer,dist[a][b][c][d]);
                }
    cout<<answer;
}