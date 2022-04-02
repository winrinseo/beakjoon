#include <iostream>
using namespace std;
int board[2200][2200];
int N;
int answer[3];
void solve(int x,int y,int width){
    bool flag = true;
    for(int i = y;i<y+width;i++){
        for(int j = x;j<x+width;j++){
            if(board[y][x]!=board[i][j]){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        if(board[y][x]==-1) answer[0]++;
        else if(board[y][x]==0) answer[1]++;
        else answer[2]++;
        return;
    }else{
        int w = width/3;
        solve(x,y,w);
        solve(x+w , y , w);
        solve(x+(w*2) , y , w);

        solve(x,y+w,w);
        solve(x+w , y+w , w);
        solve(x+(w*2) , y+w , w);

        solve(x,y+(w*2),w);
        solve(x+w , y+(w*2) , w);
        solve(x+(w*2) , y+(w*2) , w);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            cin>>board[i][j];
    solve(0,0,N);
    cout<<answer[0]<<"\n"<<answer[1]<<"\n"<<answer[2];
}