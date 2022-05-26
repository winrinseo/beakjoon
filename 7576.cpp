#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
queue<vector<int>> q;
int board[1005][1005];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int total = 0;
int N,M;
int bfs(){
    
    while(!q.empty()){
        int hr = q.front()[0];
        int hc = q.front()[1];
        int ht = q.front()[2];
        q.pop();
        total--;
        if(total==0) return ht;
        for(int i = 0;i<4;i++){
            int nr = hr+d[i][0];
            int nc = hc+d[i][1];
            if(nr<0||nr>=N||nc<0||nc>=M)
                continue;
            
            if(board[nr][nc]==-2){
                board[nr][nc] = ht+1;
                q.push({nr,nc,ht+1});
            }
        }

    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            int a;cin>>a;
            if(a==1) {
                total++;
                q.push({i,j,0});
            }
            if(a==0) {
                total++;
                board[i][j] = -2;
            }
            if(a==-1) board[i][j] = -1;
        }
    }
    cout<<bfs();
}