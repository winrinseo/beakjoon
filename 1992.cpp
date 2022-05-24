#include <iostream>

using namespace std;
int N;
char board[70][70];
void solve(int r,int c,int s){
    char ch = board[r][c];
    bool flag = true;
    for(int i = r;i<r+s;i++){
        for(int j = c;j<c+s;j++)
            if(ch!=board[i][j]){
                flag = false;
                break;
            }
        if(!flag) break;
    }
    if(flag){
        cout<<ch;
        return;
    }
    cout<<"(";
    solve(r,c,s/2);
    solve(r,c+s/2,s/2);
    solve(r+s/2,c,s/2);
    solve(r+s/2,c+s/2,s/2);
    cout<<")";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            cin>>board[i][j];


    solve(0,0,N);
}