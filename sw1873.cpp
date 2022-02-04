#include <iostream>
using namespace std;
//d = 0(up) 1(down) 2(left) 3(right)
//전차의 위치와 방향을 담은 클래스
struct Tank{
    int r,c,d;
};
int T;
int h,w;
char board[25][25];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
//벽돌로 된 벽일 경우 평지로 변경
void shoot(int r,int c,int d){
    while(1){
        r+=dir[d][0];
        c+=dir[d][1];
        //out of range
        if(r<0||r>=h||c<0||c>=w) break;
        if(board[r][c]=='#') break;
        if(board[r][c]=='*'){
            board[r][c] = '.';
            break;
        }
    }
}
//해당 방향으로 이동 가능한지 확인
bool movemove(int r,int c,int d){
    r += dir[d][0],c += dir[d][1];
    //out of range
    if(r<0||r>=h||c<0||c>=w) return false;
    if(board[r][c]=='.') return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    
    for(int i = 1;i<=T;i++){
        cin>>h>>w;
        Tank t;
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                //입력받으며 탱크위치 확인
                cin>>board[i][j];
                if(board[i][j]=='^'){
                    t.r = i, t.c = j, t.d = 0;
                    board[i][j] = '.';
                }else if(board[i][j]=='v'){
                    t.r = i, t.c = j, t.d = 1;
                    board[i][j] = '.';
                }else if(board[i][j]=='<'){
                    t.r = i, t.c = j, t.d = 2;
                    board[i][j] = '.';
                }else if(board[i][j]=='>'){
                    t.r = i, t.c = j, t.d = 3;
                    board[i][j] = '.';
                }
            }
        }
        int q;
        cin>>q;
        for(int i =0;i<q;i++){
            char query; cin>>query;
            if(query=='S'){
                shoot(t.r,t.c,t.d);
            }else if(query=='U'){
                //방향을 먼저 바꾸고 이동 가능한지만 확인
                t.d = 0;
                if(movemove(t.r,t.c,0)){
                    t.r += dir[0][0];
                    t.c += dir[0][1];
                }
            }else if(query=='D'){
                t.d = 1;
                if(movemove(t.r,t.c,1)){
                    t.r += dir[1][0];
                    t.c += dir[1][1];
                }
            }else if(query=='L'){
                t.d = 2;
                if(movemove(t.r,t.c,2)){
                    t.r += dir[2][0];
                    t.c += dir[2][1];
                }
            }else if(query=='R'){
                t.d = 3;
                if(movemove(t.r,t.c,3)){
                    t.r += dir[3][0];
                    t.c += dir[3][1];
                }
            }
        }
        //전차 방향에 맞게 설치
        if(t.d==0) board[t.r][t.c] = '^';
        else if(t.d==1) board[t.r][t.c] = 'v';
        else if(t.d==2) board[t.r][t.c] = '<';
        else if(t.d==3) board[t.r][t.c] = '>';
        cout<<'#'<<i<<" ";
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                cout<<board[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}