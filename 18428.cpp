#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;

int N;
char board[10][10];
vector<pii> T;

int d[4][2] = { {-1,0},{0,1} ,{1,0} , {0,-1}};

bool check(vector<pii> o){

    for(int i = 0;i<o.size();i++){
        board[o[i].first][o[i].second] = 'O';
    }

    for(int k = 0;k<T.size();k++){

        for(int i = 0;i<4;i++){
            int nr = T[k].first;
            int nc = T[k].second;
            while(1){
                nr += d[i][0];
                nc += d[i][1];
                
                if(nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 'O')
                    break;

                if(board[nr][nc] == 'S'){
                    for(int i = 0;i<o.size();i++){
                        board[o[i].first][o[i].second] = 'X';
                    }
                    return false;
                }
            }
        }

    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j] == 'T')
                T.push_back({i,j});
        }
    }

    int n = N*N;
    //장애물 설치
    for(int i = 0;i<n;i++){
        if(board[i/N][i%N] != 'X')
            continue; 
        
        for(int j = i + 1;j<n;j++){
            if(board[j/N][j%N] != 'X')
                continue;

            for(int z = j + 1;z<n;z++){
                if(board[z/N][z%N] != 'X')
                    continue;
                
                if(check({{i/N , i%N} ,{j/N , j%N}, {z/N , z%N }})){
                    cout<<"YES";
                    return 0;
                }
            }
        }

    }

    cout<<"NO";

}