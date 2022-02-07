#include <iostream>
#include <queue>
using namespace std;
int N,M;
int H,W;
pair<int,int> s,f;
bool board[1005][1005];
int visited[1005][1005];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool isvalid(int r,int c){
    if(r+H-1>N||r<1||c+W-1>M||c<1) {
        visited[r][c] = -1;
        return false;
    }
    if(board[r][c]){
        visited[r][c] = -1;
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            cin>>board[i][j];
            if(board[i][j]){
                for(int a = i;a>=i-H+1;a--){
                    if(a<1) break;
                    for(int b = j;b>=j-W+1;b--){
                        if(b<1) break;
                        board[a][b] = 1;
                    }
                }
            }
        }
    }
    cin>>H>>W>>s.first>>s.second>>f.first>>f.second;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(board[i][j]){
                for(int a = i;a>=i-H+1;a--){
                    if(a<1) break;
                    for(int b = j;b>=j-W+1;b--){
                        if(b<1) break;
                        board[a][b] = 1;
                    }
                }
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({s.first,s.second});
    
    while(!q.empty()){
        int hr = q.front().first;
        int hc = q.front().second;
        q.pop();
        if(hr==f.first&&hc==f.second){
            cout<<visited[hr][hc];
            return 0;
        }
        for(int i = 0;i<4;i++){
            int nr = hr+d[i][0];
            int nc = hc+d[i][1];
            if(visited[nr][nc])
                continue;
            if(isvalid(nr,nc)){
                visited[nr][nc] = visited[hr][hc]+1;
                q.push({nr,nc});
            }
        }
    }
    cout<<-1;
}