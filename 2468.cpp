#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
using namespace std;
int N;
int visited[105][105];
int board[105][105];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
void bfs(int r,int c,int h){
    queue<pii> q;
    visited[r][c] = h;
    q.emplace(r,c);
    while(!q.empty()){
        pii cur = q.front();q.pop();
        for(int i = 0;i<4;i++){
            int nr = cur.first+d[i][0];
            int nc = cur.second+d[i][1];

            if(nr<0||nr>=N||nc<0||nc>=N)
                continue;
            if(visited[nr][nc]==h||board[nr][nc] <= h)
                continue;
            
            visited[nr][nc] = h;
            q.emplace(nr,nc);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int minH = 105,maxH = -1;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++){
            cin>>board[i][j];
            minH = min(minH,board[i][j]);
            maxH = max(maxH,board[i][j]);
        }
            
    int answer = 1;
    for(int h = minH;h <= maxH;h++){
        int area = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(visited[i][j]<h&&board[i][j] > h){
                    bfs(i,j,h);
                    area++;
                }
            }
        }
        answer = max(answer,area);
    }
    cout<<answer;
}