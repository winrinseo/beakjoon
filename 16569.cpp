#include <iostream>
#include <queue>
#define INF 1000000
using namespace std;

int M,N,V;
int map[105][105];
int alt[105][105];
bool volcaino[105][105];
bool visited[105][105];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N>>V;
    queue<vector<int>> q;

    int x,y;
    cin>>x>>y;
    
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            cin>>alt[i][j];
        }
    }

    for(int i = 0;i<V;i++){
        int a,b,c;
        cin>>a>>b>>c;
        q.push({a - 1,b - 1,c});
        map[a-1][b-1] = c;
        volcaino[a-1][b-1] = true;
    }

    // 화산쇄설류가 덮이는 시간 계산
    while(!q.empty()){
        vector<int> cur = q.front();q.pop();

        for(int i = 0;i<4;i++){
            int nr = cur[0] + d[i][0];
            int nc = cur[1] + d[i][1];

            if(nr < 0 || nc < 0 || nr >= M || nc >= N)
                continue;

            if(map[nr][nc] == 0 || map[nr][nc] > cur[2] + 1){
                map[nr][nc] = cur[2] + 1;
                q.push({nr,nc,map[nr][nc]});
            }
        }
    }

    visited[x-1][y-1] = true; 
    q.push({x-1,y-1,0});
    int answer = 0;
    int time = 0;
    while(!q.empty()){
        vector<int> cur = q.front();q.pop();
        if(answer < alt[cur[0]][cur[1]]){
            answer = alt[cur[0]][cur[1]];
            time = cur[2];
        }
        for(int i = 0;i<4;i++){
            int nr = cur[0] + d[i][0];
            int nc = cur[1] + d[i][1];
            int nt = cur[2] + 1;
            if(nr < 0 || nc < 0 || nr >= M || nc >= N)
                continue;

            if(visited[nr][nc] || volcaino[nr][nc])
                continue;
            if(map[nr][nc] <= nt)
                continue;
            
            visited[nr][nc] = true;
            q.push({nr,nc,nt});
        }
    }
    cout<<answer<<" "<<time;
}