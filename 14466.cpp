#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int,int>
using namespace std;

int N,K,R;
int board[105][105];
bool br[105][105][4];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

bool visited[105][105];
queue<pii> q;

vector<int> cluster;

int bfs(pii s){
    visited[s.first][s.second] = 1;
    q.push(s);
    int ret = 0;

    while(!q.empty()){
        pii cur = q.front();q.pop();
        if(board[cur.first][cur.second])
            ret++;
        
        for(int i = 0;i<4;i++){
            if(br[cur.first][cur.second][i])
                continue;
            int nr = cur.first + d[i][0];
            int nc = cur.second + d[i][1];

            if(nr < 1 || nr > N || nc < 1 || nc > N)
                continue;
            
            if(visited[nr][nc])
                continue;
            
            visited[nr][nc] = 1;

            q.push({nr,nc});
        }
        
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K>>R;

    for(int i = 0;i<R;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;

        int y = c-a;
        int x = d-b;
        int dir = -1;
        if(y == -1) dir = 0;
        else if(y == 1) dir = 2;
        else if(x == 1) dir = 1;
        else dir = 3;

        br[a][b][dir] = 1;
        br[c][d][(dir+2)%4] = 1;
    }

    for(int i = 0;i<K;i++){
        int a,b;cin>>a>>b;
        board[a][b] = 1;
    }

    for(int i = 1;i<=N;i++){
        for(int j = 1; j<=N;j++){
            if(visited[i][j])
                continue;
            cluster.push_back(bfs({i , j}));
        }
    }
    
    int ans = 0;

    for(int i = 0;i<cluster.size();i++){
        
        for(int j = i + 1; j<cluster.size();j++){
            ans += (cluster[i] * cluster[j]);
        }
    }
    cout<<ans;
}