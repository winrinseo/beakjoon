#include <iostream>
using namespace std;
int board[9][9];
//비트마스킹
int row_check[9];
int col_check[9];
int grid_check[9];
int gridnum(int r,int c){
    return (r/3)*3 + (c/3);
}
void bit_mask(int r,int c,int i,bool b){
    if(b){
        row_check[r] |= (1<<i);
        col_check[c] |= (1<<i);
        grid_check[gridnum(r,c)] |= (1<<i);
    }else{
        row_check[r] &= ~(1<<i);
        col_check[c] &= ~(1<<i);
        grid_check[gridnum(r,c)] &= ~(1<<i);
    }
}
void print_board(){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve(){
    int r=-1,c=-1;
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(board[i][j]==0){
                r = i,c = j;
            }
            if(r!=-1) break;
        }
        if(r!=-1) break;
    }
    // 정답을 찾았을 경우
    if(r==-1){
        print_board();
        exit(0);
    }
    for(int i = 1;i<=9;i++){
        if(row_check[r]&(1<<i)||col_check[c]&(1<<i)
        ||grid_check[gridnum(r,c)]&(1<<i))
            continue;
        else{
            bit_mask(r,c,i,true);
            board[r][c] = i;
            solve();
            bit_mask(r,c,i,false);
            board[r][c] = 0;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            cin>>board[i][j];
            if(board[i][j]!=0){
                row_check[i] |= (1<<board[i][j]);
                col_check[j] |= (1<<board[i][j]);
                grid_check[gridnum(i,j)] |= (1<<board[i][j]);
            }
        }
    }
    solve();
}