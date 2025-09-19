#include <iostream>
#include <queue>
#define INF 987654321
#define pii pair<int,int>

using namespace std;

int N,M,K;
// 0 : 시루 , 1 : 마네킹
int dist[2005][2005][2];
int m[2005][2005];
vector<pii> v[2];

int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void bfs(int c){
    queue<pii> q;
    
    for(pii & pos : v[c]){
        q.push(pos);
        dist[pos.first][pos.second][c] = 0;
    }


    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        
        for(int i = 0;i<4;i++){
            int nr = cur.first + d[i][0];
            int nc = cur.second + d[i][1];

            if(nr >= N || nr < 0 || nc >= M || nc < 0)
                continue;
            
            if(c == 0 && m[nr][nc] == 1)
                continue;
            
            if(c == 0 && dist[nr][nc][1] <= K)
                continue;
            
            if(dist[nr][nc][c] != INF)
                continue;

            dist[nr][nc][c] = dist[cur.first][cur.second][c] + 1;
            q.push({nr,nc});
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>K;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin>>m[i][j];
            if(m[i][j] == 4)
                v[0].push_back({i,j});
            if(m[i][j] == 3)
                v[1].push_back({i,j});

            for(int k = 0;k<2;k++)
                dist[i][j][k] = INF;
        }
    }

    bfs(1);
    bfs(0);

    int answer = INF;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(m[i][j] == 2){
                answer = min(answer , dist[i][j][0]);
            }
        }
    }
    if(answer == INF)
        cout<<-1;
    else cout<<answer;
}