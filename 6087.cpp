#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define pii pair<int,int>
using namespace std;
struct Point{
    int r,c,shift,prevd;
};
struct cmp{
    bool operator()(Point& a,Point& b){
        return a.shift > b.shift;
    }
};
int W,H;
char board[105][105];
int visited[105][105][5];
vector<pii> p;
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int bfs(){
    for(int i = 0;i<H;i++)
        for(int j = 0;j<W;j++)
            for(int z = 0;z<5;z++)
                visited[i][j][z] = INF;
    priority_queue<Point,vector<Point>,cmp> pq;
    pii& src = p[0];
    pii& dst = p[1];
    visited[src.first][src.second][4] = 0;
    pq.push({src.first,src.second,-1,-1});

    while(!pq.empty()){
        Point cur = pq.top();pq.pop();
        if(cur.r==dst.first&&cur.c==dst.second)
            return cur.shift;
        
        for(int i = 0;i < 4;i++){
            int nr = cur.r+d[i][0];
            int nc = cur.c+d[i][1];
            int ns = i!=cur.prevd?cur.shift+1:cur.shift;
            if(nr<0||nr>=H||nc<0||nc>=W)
                continue;
            if(board[nr][nc]=='*')
                continue;
            if(visited[nr][nc][i] > ns){
                visited[nr][nc][i] = ns;
                pq.push({nr,nc,ns,i});
            }

        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>W>>H;
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            cin>>board[i][j];
            if(board[i][j]=='C'){
                p.push_back({i,j});
            }
        }
    }

    cout<<bfs();
}