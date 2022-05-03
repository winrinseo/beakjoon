#include <iostream>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;
int R,C;
char board[1005][1005];
int f[1005][1005],visited[1005][1005];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
queue<pii> fire;
void bfs1(){
    while(!fire.empty()){
        pii cur = fire.front();fire.pop();

        for(int i = 0;i<4;i++){
            int nr = cur.first+d[i][0];
            int nc = cur.second+d[i][1];
            if(nr<0||nr>R||nc<0||nc>C)
                continue;
            if(board[nr][nc]=='#')
                continue;
            if(f[nr][nc]>f[cur.first][cur.second]+1){
                f[nr][nc] = f[cur.first][cur.second]+1;
                fire.push({nr,nc});
            }
        }
    }
}
int bfs2(pii st){
    queue<pii> q;
    visited[st.first][st.second] = 0;
    q.push({st.first,st.second});
    while(!q.empty()){
        pii cur = q.front();q.pop();
        if(cur.first==1||cur.first==R||cur.second==1||cur.second==C)
            return visited[cur.first][cur.second]+1;

        for(int i = 0;i<4;i++){
            int nr = cur.first+d[i][0];
            int nc = cur.second+d[i][1];
            int nd = visited[cur.first][cur.second]+1;
            if(nr<0||nr>R||nc<0||nc>C)
                continue;
            if(board[nr][nc]=='#'||f[nr][nc] <= nd)
                continue;
            if(visited[nr][nc] > nd){
                visited[nr][nc] = nd;
                q.push({nr,nc});
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;  
    pii st;
    for(int i = 1; i<=R;i++){
        for(int j = 1;j<=C;j++){
            f[i][j] = INF;
            visited[i][j] = INF;
            cin>>board[i][j];
            if(board[i][j]=='F'){
                fire.push({i,j});
                f[i][j] = 0;
            }
            if(board[i][j]=='J')
                st = {i,j};
        }
    }
    bfs1();
    int answer = bfs2(st);
    if(answer < 0) cout<<"IMPOSSIBLE";
    else cout<<answer;
}