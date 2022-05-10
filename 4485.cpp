#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
struct Point{
    int r,c,cost;
};
struct cmp{
    bool operator()(Point& a,Point& b){
        return a.cost > b.cost;
    }
};
int T,N;
int board[130][130];
int dist[130][130];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int dij(){
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            dist[i][j] = INF;
    priority_queue<Point,vector<Point>,cmp> pq;
    dist[0][0] = board[0][0];

    pq.push({0,0,board[0][0]});

    while(!pq.empty()){
        Point cur = pq.top();
        pq.pop();
        if(cur.r == N-1&&cur.c==N-1)
            return cur.cost;
        
        for(int i = 0;i<4;i++){
            int nr = cur.r+d[i][0];
            int nc = cur.c+d[i][1];
            if(nr<0||nr>=N||nc<0||nc>=N)
                continue;
            int ncost = cur.cost+board[nr][nc];
            if(dist[nr][nc] > ncost){
                dist[nr][nc] = ncost;
                pq.push({nr,nc,ncost});
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(cin>>N){
        if(!N) break;
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
                cin>>board[i][j];
            
        int ans = dij();
        cout<<"Problem "<<t<<": "<<ans<<"\n";
        t++;
    }
}