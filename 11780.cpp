#include <iostream>
#include <list>
#define pii pair<int,int>
using namespace std;

int N,K;
//말 , 방향
list<pii> board[15][15];
int map[15][15];
//말의 위치
pii h[15];
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}; 
int main(){
    
    cin>>N>>K;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin>>map[i][j];
        }
    }

    for(int i = 1;i<=K;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;c--;
        h[i] = {a, b};
        board[a][b].push_back({i , c});

    }


    int answer = 1;

    while(answer <= 1000){


        for(int i = 1;i<=K;i++){
            int r = h[i].first;
            int c = h[i].second;
            pii d = board[r][c].front();
            
            //맨 아래의 말이 아니면 생략
            if(d.first != i) continue;

            int nr = r + dir[d.second][0];
            int nc = c + dir[d.second][1];

            //파란 칸이거나 칸 밖으로 나간 경우
            if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == 2){
                //방향 바꿈
                if(d.second < 2){
                    board[r][c].front().second = (d.second + 1) % 2;
                }else{
                    board[r][c].front().second = (d.second + 1) == 4 ? 2 : 3;
                }
                d = board[r][c].front();
                nr = r + dir[d.second][0];
                nc = c + dir[d.second][1];
                
                //방향을 바꾸고도 파란칸인 경우
                if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == 2)
                    continue;

            }
            
            if(map[nr][nc] == 1){//미리 뒤집기
                board[r][c].reverse();
            }


            //옮기기
            while(!board[r][c].empty()){
                pii next = board[r][c].front();
                h[next.first] = {nr , nc};
                board[nr][nc].push_back(next);
                board[r][c].pop_front();

            }
            
            //종료조건
            if(board[nr][nc].size() >= 4){
                cout<<answer;
                return 0;
            }

        }
        answer++;
    }
    cout<<-1;
}