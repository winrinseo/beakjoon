#include <iostream>
using namespace std;

string board;

void solve(int st){
    if(st>=board.size()){
        cout<<board;
        exit(0);
    }
    bool flag = true;
    if(st+4<=board.size()){
        for(int i = st;i<st+4;i++)
            if(board[i]=='.')
                flag = false;
        if(flag){
            for(int i = st;i<st+4;i++)
                board[i] = 'A';
            solve(st+4);
            for(int i = st;i<st+4;i++)
                board[i] = 'X';
        }
    }
    flag = true;
    if(st+2<=board.size()){
        for(int i = st;i<st+2;i++)
            if(board[i]=='.')
                flag = false;
        if(flag){
            for(int i = st;i<st+2;i++)
                board[i] = 'B';
            solve(st+2);
            for(int i = st;i<st+2;i++)
                board[i] = 'X';
        }
    }
    if(board[st]=='.')
        solve(st+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>board;
    solve(0);
    cout<<-1;
}