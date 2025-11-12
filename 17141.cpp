#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define pii pair<int,int>
using namespace std;

int N,M;
int map[55][55];
int visited[55][55];
int n;
vector<pii> virus;
vector<pii> sel;
queue<pii> q;
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int bfs(){
    memset(visited , 0 , sizeof(visited));

    int reach = n;
    for(int i = 0;i<M;i++){
        q.push(sel[i]);
        visited[sel[i].first][sel[i].second] = 1;
        
    }
    
    int ret = 1;
    while(!q.empty()){
        pii cur = q.front();q.pop();
        reach--;
        for(int i = 0;i<4;i++){
            int nr = cur.first + d[i][0];
            int nc = cur.second + d[i][1];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
            
            if(map[nr][nc] == 1)
                continue;

            if(visited[nr][nc])
                continue;

            q.push({nr,nc});
            visited[nr][nc] = visited[cur.first][cur.second] + 1;
            ret = max(ret , visited[nr][nc]);
        }
    }
    
    return reach > 0 ? (1<<30) : ret - 1;
}

int solve(int cur){
    if(sel.size() == M)
        return bfs();
    
    if(cur >= virus.size())
        return (1<<30);

    int ret = (1<<30);
    sel.push_back(virus[cur]);
    ret = min(ret , solve(cur + 1));
    sel.pop_back();

    ret = min(ret , solve(cur + 1));
    
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    n = N*N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin>>map[i][j];
            if(map[i][j] == 2)
                virus.push_back({i,j});
            if(map[i][j] == 1)
                n--;
        }
    }

    int answer = solve(0);

    if(answer == (1<<30))
        cout<<-1;
    else cout<<answer;
}