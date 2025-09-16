#include <iostream>
#include <queue>
#define INF 987654321
#define pii pair<int,int>
#define MAX (1<<10)-1
using namespace std;

int N;

int dist[15][105][105];

pii st[15];

int d[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};

int dp[15][MAX];

int cnt = 1;

void bfs(int idx){


    queue<pii> q;
    q.push(st[idx]);
    dist[idx][st[idx].first][st[idx].second] = 0;


    while(!q.empty()){

        pii cur = q.front();q.pop();

        for(int i = 0;i<4;i++){
            int nr = cur.first + d[i][0];
            int nc = cur.second + d[i][1];

            if(nr >=N || nr < 0 || nc >= N || nc < 0)
                continue;

            if(dist[idx][nr][nc] != INF)
                continue;
            
            dist[idx][nr][nc] = dist[idx][cur.first][cur.second] + 1;
            q.push({nr,nc});
        }
        
    }

}

int solve(int cur , int bit){
    
    if(bit == (1<<cnt) - 1) return 0;
    int & ret = dp[cur][bit];
    if(ret != 0) return ret;

    ret = INF;
    
    for(int i = 0;i<cnt;i++){
        if((!(bit & (1<<i))) && dist[cur][st[i].first][st[i].second] != INF){
            ret = min(ret , solve(i , bit | (1<<i)) + dist[cur][st[i].first][st[i].second]);
        }
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            int a;cin>>a;
            if(a == 2) st[0] = {i,j};
            if(a == 1) st[cnt++] = {i,j};
        }
    }
    
    if(cnt == 1) {
        cout<<"Undertaker"<<"\n";
        cout<<0;
        return 0;
    }

    for(int k = 0;k<cnt;k++)
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
                dist[k][i][j] = INF;
            
    

    for(int i = 0;i<cnt;i++)
        bfs(i);

    int answer = solve(0 , 1);

    if(answer == INF)
        cout<<"Shorei";
    else{
        cout<<"Undertaker"<<'\n';
        cout<<answer;
    }

}