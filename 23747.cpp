#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;
char board[1005][1005];
bool ww[1005][1005];
int N,M;
int r,c;
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void bfs(int y,int x){
    ww[y][x] = 1;
    queue<pii> q;
    q.push({y,x});
    char cur = board[y][x];
    while(!q.empty()){
        int hr = q.front().first;
        int hc = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nr = hr+d[i][0];
            int nc = hc+d[i][1];

            if(nr<1||nr>N||nc<1||nc>M)
                continue;
            if(cur!=board[nr][nc])
                continue;
            if(!ww[nr][nc]){
                ww[nr][nc] = 1;
                q.push({nr,nc});
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 1;i<=N;i++)
        for(int j = 1;j<=M;j++)
            cin>>board[i][j];
    int r,c;
    cin>>r>>c;
    string cmd;
    cin>>cmd;
    for(int i = 0;i<cmd.size();i++){
        int dir = -1;
        if(cmd[i]=='U') dir = 0;
        else if(cmd[i]=='R') dir = 1;
        else if(cmd[i]=='D') dir = 2;
        else if(cmd[i]=='L') dir = 3;
        else bfs(r,c);
        if(dir!=-1){
            r+=d[dir][0];
            c+=d[dir][1];
        }
        
    }
        ww[r][c] = 1;
        for(int i = 0;i<4;i++){
            int nr = r+d[i][0];
            int nc = c+d[i][1];
            if(nr<1||nr>N||nc<1||nc>M)
                continue;
            if(!ww[nr][nc]){
                ww[nr][nc] = 1;
            }
        }

        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=M;j++){
                if(ww[i][j]) cout<<'.';
                else cout<<"#";
            }
            cout<<'\n';
        }
            
}