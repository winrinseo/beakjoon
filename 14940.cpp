#include <iostream>
#include <queue>
#define pii pair<int,int>

using namespace std;

int N , M;
int board[1005][1005];
int dist[1005][1005];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    queue<pii> q;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j] == 2)
                q.push({i,j});
        }
    }




    while(!q.empty()){
        pii cur = q.front();q.pop();

        for(int i = 0;i<4;i++){
            int nr = cur.first + d[i][0];
            int nc = cur.second + d[i][1];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if(dist[nr][nc] != 0 || board[nr][nc] == 2 || board[nr][nc] == 0)
                continue;

            dist[nr][nc] = dist[cur.first][cur.second] + 1;
            q.push({nr,nc});
        }

    }

    

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(dist[i][j] == 0 && board[i][j] == 1)
                cout<<-1<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}