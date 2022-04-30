#include <iostream>
#include <queue>
using namespace std;
int T,N,M,K;
int board[55][55];
bool visited[55][55];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
void bfs(int y,int x){  
    queue<pair<int,int>> q;
    visited[y][x] = 1;
    q.push({y,x});

    while(!q.empty()){
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int ny = hy+d[i][0];
            int nx = hx+d[i][1];
            if(ny<0||ny>=N||nx<0||nx>=M)
                continue;
            if(board[ny][nx]&&!visited[ny][nx]){
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>M>>N>>K;
        for(int i = 0;i<N;i++)
            for(int j = 0;j<M;j++){
                visited[i][j] = 0;
                board[i][j] = 0;
            }
                
        for(int i = 0;i<K;i++){
            int a,b;cin>>a>>b;
            board[b][a] = 1;
        }
        
        int answer = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                if(board[i][j]&&!visited[i][j]){
                    answer++;
                    bfs(i,j);
                }
            }
        }
        cout<<answer<<"\n";
    }
    
}