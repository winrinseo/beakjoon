#include <iostream>
#include <queue>

using namespace std;

int N , M , K;
int map[1005][1005];
bool visited[1005][1005];
int d[6][2] = {{0,-1} , {0,1} , {1,0},{1,1},{-1,0},{-1,1}};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>K;

    for(int i = 0;i<K;i++){
        int a,b;cin>>a>>b;
        visited[a][b] = true;
    }

    queue<vector<int>> q;

    q.push({0,0,0});
    visited[0][0] = true;

    while(!q.empty()){
        vector<int> cur = q.front();q.pop();
        
        for(int i = 0;i<6;i++){
            int nr = cur[0] + d[i][0];
            int nc = cur[1];
            if(i >= 2 && cur[0] % 2 == 0)
                nc -= d[i][1];
            else nc += d[i][1];

            if(nr < 0 || nc < 0 || nr >= N || nc >= M)
                continue;
            if(visited[nr][nc])
                continue;
            
            map[nr][nc] = cur[2] + 1;
            visited[nr][nc] = true;

            q.push({nr,nc,cur[2] + 1});
        }
    }

    if(!visited[N-1][M-1]) cout<<-1;
    else cout<<map[N-1][M-1];
}