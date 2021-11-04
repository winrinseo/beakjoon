#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int B;
int board[505][505];
int getT(int h){
    int inven = B;
    int ret = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(board[i][j] > h){
                inven+=(board[i][j]-h);
                ret+=((board[i][j]-h)*2);
            }
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(board[i][j] < h){
                inven-=(h-board[i][j]);
                ret+=(h-board[i][j]);
            }
            if(inven < 0) return -1;
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>B;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
            cin>>board[i][j];
        
    //시간 , 높이
    int answer[2] = {INT32_MAX-1,0};
    for(int i = 0;i<=256;i++){
        int time = getT(i);
        if(time == -1) continue;
        if(answer[0] > time){
            answer[0] = time;
            answer[1] = i;
        }else if(answer[0]==time){
            answer[1] = max(answer[1],i);
        }
    }
    cout<<answer[0]<<" "<<answer[1];
}