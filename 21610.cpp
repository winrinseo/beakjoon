#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;
int N,M;
int board[55][55];
//이번 턴에 구름이 사라졌던곳 체크
//여기선 물이 2이상이어도 구름이 안생겨남
bool ban[55][55];
int d[8][2]={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
//이동할 위치를 반환해줌
pii move(pii coor,int dir,int m){
    coor.first += (d[dir-1][0]*m);
    coor.second += (d[dir-1][1]*m);
    while(coor.first < 0) coor.first+=N;
    if(coor.first >= N) coor.first%=N;
    while(coor.second < 0) coor.second+=N;
    if(coor.second >= N) coor.second%=N;
    return {coor.first,coor.second};
}
void bug(pii coor){
    for(int i = 1;i<8;i+=2){
        int nr = coor.first+d[i][0];
        int nc = coor.second+d[i][1];
        if(nr<0||nr>=N||nc<0||nc>=N)
            continue;
        if(board[nr][nc] > 0) board[coor.first][coor.second]++;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            cin>>board[i][j];
    
    queue<pii> cloud,water;
    cloud.push({N-1,0});
    cloud.push({N-1,1});
    cloud.push({N-2,0});
    cloud.push({N-2,1});

    while(M--){
        int dir,m;cin>>dir>>m;
        //모든 구름 이동
        while(!cloud.empty()){
            pii coor = move(cloud.front(),dir,m);
            cloud.pop();
            board[coor.first][coor.second] += 1;
            ban[coor.first][coor.second] = 1;
            water.push({coor.first,coor.second});
        }
        
        //물복사 버그
        while(!water.empty()){
            pii coor = water.front();
            water.pop();
            bug(coor);
        }

        //구름 생성
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(ban[i][j]){
                    ban[i][j] = 0;
                }else if(board[i][j]>=2){
                    cloud.push({i,j});
                    board[i][j]-=2;
                }
            }
        }
        

    }
    int answer = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            
            answer+=board[i][j];
        }
    }
    cout<<answer;
}