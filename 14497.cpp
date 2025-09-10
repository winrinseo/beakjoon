#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;

int N,M;
int dist[305][305];
pii target , start;
string map[305];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int bfs(int turn){
    queue<pii> q;
    q.push(start);
    dist[start.first][start.second] = turn;
    
    while(!q.empty()){
        pii cur = q.front();q.pop();

        if(cur.first == target.first && cur.second == target.second)
            return true;

        if(map[cur.first][cur.second] == '1'){
            map[cur.first][cur.second] = '0';
            continue;
        }

        for(int i = 0;i<4;i++){
            int nr = cur.first + d[i][0];
            int nc = cur.second + d[i][1];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            
            if(dist[nr][nc] == turn)
                continue;
            
            dist[nr][nc] = turn;
            q.push({nr,nc});
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    cin>>start.first>>start.second;
    cin>>target.first>>target.second;
    start.first--,start.second--,target.first--,target.second--;
    for(int i = 0;i<N;i++){
        cin>>map[i];
    }

    int cnt = 1;

    while(1){
    
        if(bfs(cnt)){
            cout<<cnt;
            return 0;
        }
        cnt++;
    }

}
