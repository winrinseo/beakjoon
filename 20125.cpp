#include <iostream>

using namespace std;
int N;
char board[1005][1005];
int headY,headX;
int heartY,heartX;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cin>>board[i][j];
            if(headY == 0 && board[i][j] == '*')
                headY = i , headX = j;
        }
    }
    heartY = headY+1;
    heartX = headX;

    cout<<heartY <<" "<<heartX<<"\n";

    int cnt = 0;
    int y = heartY , x = heartX;
    while(x > 0 && x <= N && y > 0 && y <=N){
        --x;
        if(board[y][x] == '*') cnt++;
        else break;
    }
    cout<<cnt<<" ";

    cnt = 0;
    y = heartY , x = heartX;
    while(x > 0 && x <= N && y > 0 && y <=N){
        ++x;
        if(board[y][x] == '*') cnt++;
        else break;
    }
    cout<<cnt<<" ";

    cnt = 0;
    y = heartY , x = heartX;
    while(x > 0 && x <= N && y > 0 && y <=N){
        ++y;
        if(board[y][x] == '*') cnt++;
        else break;
    }
    cout<<cnt<<" ";
    
    int scnt = cnt;
    cnt = 0;
    y = heartY + scnt + 1 , x = heartX - 1;
    while(x > 0 && x <= N && y > 0 && y <=N){
        ++y;
        if(board[y][x] == '*') cnt++;
        else break;
    }
    cout<<cnt+1<<" ";

    cnt = 0;
    y = heartY + scnt + 1 , x = heartX + 1;
    while(x > 0 && x <= N && y > 0 && y <=N){
        ++y;
        if(board[y][x] == '*') cnt++;
        else break;
    }
    cout<<cnt+1<<" ";
}