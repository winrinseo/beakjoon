#include <iostream>
#include <queue>
#define EMPTY 987654321
using namespace std;
struct Point{
    int d , r , c;
};
struct cmp{
    bool operator () (Point & a , Point & b){
        return a.d > b.d;
    }
};

int N , M;

int visited[105][105];
char map[105][105];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
priority_queue<Point,vector<Point>,cmp> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>M>>N;

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            cin>>map[i][j];
            visited[i][j] = EMPTY;
        }
    }

    pq.push({0,1,1});
    visited[1][1] = 0;


    while(!pq.empty()){
        Point cur = pq.top(); pq.pop();
        
        for(int i = 0;i<4;i++){
            int nr = cur.r + d[i][0];
            int nc = cur.c + d[i][1];

            if(nr < 1 || nr > N || nc < 1 || nc > M)
                continue;

            if(visited[nr][nc] > cur.d + (map[nr][nc] - '0')){
                visited[nr][nc] = cur.d + (map[nr][nc] - '0');
                pq.push({cur.d + (map[nr][nc] - '0') , nr, nc});
            }
        }
    }

    cout<<visited[N][M];
}