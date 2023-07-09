#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
struct Point{
    int d, n ,c;
};

int S;
bool visited[1005][1005];
int bfs(){
    queue<Point> q;
    visited[1][0] = 1;

    q.push({0,1,0});

    while(!q.empty()){
        Point cur = q.front();q.pop();
        if(cur.n == S) return cur.d;
        //클립보드 저장
        if(!visited[cur.n][cur.n]){
            visited[cur.n][cur.n] = 1;
            q.push({cur.d+1,cur.n,cur.n});
        }
        if(cur.n+cur.c < 1005 && !visited[cur.n+cur.c][cur.c]){
            visited[cur.n+cur.c][cur.c] = 1;
            q.push({cur.d+1,cur.n+cur.c,cur.c});
        }
        if(cur.n-1 >= 0&& !visited[cur.n-1][cur.c]){
            visited[cur.n-1][cur.c] = 1;
            q.push({cur.d+1,cur.n-1,cur.c});
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>S;
    cout<<bfs();
}