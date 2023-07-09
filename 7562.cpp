#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;

int T,I;
int src[2],dst[2];
int d[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int visited[305][305];
int bfs(){
    for(int i = 0;i<I;i++)
        for(int j = 0;j<I;j++)
            visited[i][j] = 0;
    queue<pii> q;
    q.push({src[0],src[1]});
    visited[src[0]][src[1]] = 1;
    while(!q.empty()){
        pii cur = q.front();q.pop();
        if(cur.first == dst[0] && cur.second == dst[1])
            return visited[cur.first][cur.second]-1;
        
        for(int i = 0;i<8;i++){
            int nr = cur.first+d[i][0];
            int nc = cur.second+d[i][1];
            if(nr<0||nr>=I||nc<0||nc>=I)
                continue;
            if(!visited[nr][nc]){
                visited[nr][nc] = visited[cur.first][cur.second]+1;
                q.push({nr,nc});
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        cin>>I;
        cin>>src[0]>>src[1];
        cin>>dst[0]>>dst[1];

        cout<<bfs()<<"\n";

    }
}