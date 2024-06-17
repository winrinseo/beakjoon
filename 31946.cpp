#include <iostream>
#include <queue>
using namespace std;

int N , M , X;

int map[105][105];
bool visited[105][105];

int d[4][2] = {{-1,0} ,{1,0},{0,1},{0,-1}};

queue<pair<int,int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;


    for(int i = 1;i<=N;i++)
        for(int j = 1; j<=M;j++)
            cin>>map[i][j];

    cin>>X;
        
    if(map[N][M] != map[1][1]){
        cout<<"DEAD";
        return 0;
    }

    q.push({1,1});

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();

        if(cur.first == N && cur.second == M){
            cout<< "ALIVE";
            return 0;
        }

        for(int r = -X ;r<=X;r++){

            int C = X - abs(r);
            
            for(int c = -C; c<= C;c++){
                int nr = cur.first + r;
                int nc = cur.second + c;

                if(nr < 1 || nr > N ||nc < 1 || nc > M)
                    continue;

                if(map[nr][nc] != map[1][1] || visited[nr][nc])
                    continue;

                visited[nr][nc] = 1;

                q.push({nr,nc});
                
            }
                
        }

    }
    cout<<"DEAD";
}