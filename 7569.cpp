#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
queue<vector<int>> q;
int board[105][105][105];
int d[6][3] = {{0,0,1},{0,0,-1},{-1,0,0},{0,1,0},{1,0,0},{0,-1,0}};
int total = 0;
int N,M,H;
int bfs(){
    
    while(!q.empty()){
        int hr = q.front()[0];
        int hc = q.front()[1];
        int hh = q.front()[2];
        int ht = q.front()[3];
        q.pop();
        total--;
        if(total==0) return ht;
        for(int i = 0;i<6;i++){
            int nr = hr+d[i][0];
            int nc = hc+d[i][1];
            int nh = hh+d[i][2];

            if(nr<0||nr>=N||nc<0||nc>=M||nh<0||nh>=H)
                continue;
            
            if(board[nr][nc][nh]==-2){
                board[nr][nc][nh] = ht+1;
                q.push({nr,nc,nh,ht+1});
            }
        }

    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N>>H;
    for(int h = 0;h<H;h++){
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                int a;cin>>a;
                if(a==1) {
                    total++;
                    q.push({i,j,h,0});
                }
                if(a==0) {
                    total++;
                    board[i][j][h] = -2;
                }
                if(a==-1) board[i][j][h] = -1;
            }
        }
    }
    cout<<bfs();
}