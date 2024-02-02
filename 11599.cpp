#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;

char board[12][6];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

vector<pii> bfs(int y , int x){
    bool visited[12][6] = {0};
    char c = board[y][x];
    queue<pii> q;
    q.push({y,x});
    visited[y][x] = true;
    vector<pii> ret;

    while(!q.empty()){
        pii cur = q.front();q.pop();
        ret.push_back(cur);
        for(int i = 0;i<4;i++){
            int nr = cur.first + d[i][0];
            int nc = cur.second + d[i][1];
            if(nr < 0 || nr >= 12 || nc < 0 || nc >= 6)
                continue;
            if(visited[nr][nc]) continue;
            if(board[nr][nc] == c){
                visited[nr][nc] = true;
                q.push({nr,nc});
            }
        }
    }
    return ret;
}

void reBoard(){
    stack<char> s;

    for(int j = 0; j < 6; j++){
        
        for(int i = 0;i<12;i++){
            if(board[i][j] != '.'){
                s.push(board[i][j]);
                board[i][j] = '.';
            }
        }

        for(int i = 11;i>=0;i--){
            if(s.empty()) break;
            board[i][j] = s.top();
            s.pop();
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0;i<12;i++){
        for(int j = 0;j<6;j++){
            cin>>board[i][j];
        }
    }

    int answer = 0;

    while(1){
        bool flag = false;
        for(int i = 0;i<12;i++){
            for(int j = 0;j<6;j++){
                if(board[i][j] != '.'){
                    vector<pii> pos = bfs(i , j);
                    
                    if(pos.size() >= 4){
                        
                        flag = true;
                        for(pii & p : pos)
                            board[p.first][p.second] = '.';
                    }
                }
            }
        }
        if(flag) answer++;
        else break;

        reBoard();
    }
    cout<<answer;
}