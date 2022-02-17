#include <iostream>

using namespace std;
char board[10005][505];
int r,c;
int d[3][2] = {{-1,1},{0,1},{1,1}};
bool flag;
int answer = 0;
void dfs(int cr,int cc){
    if(cc==c-1){
        flag = true;
        return;
    }
    for(int i = 0;i<3;i++){
        int nr = cr+d[i][0];
        int nc = cc+d[i][1];
        if(nr<0||nr>=r||nc<0||nc>=c)
            continue;
        if(board[nr][nc]=='x') continue;
        board[nr][nc] = 'x';
        dfs(nr,nc);
        if(flag) return;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>c;

    for(int i = 0;i<r;i++)
        for(int j =0;j<c;j++)
            cin>>board[i][j];
    
    for(int i = 0;i<r;i++){
        flag = false;
        dfs(i,0);
        if(flag) answer++;
    }
    cout<<answer;
}