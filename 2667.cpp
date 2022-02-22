#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N;
string board[30];
vector<int> answer;
bool visited[30][30];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
void bfs(int y,int x){
    visited[y][x] = true;
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();
        cnt++;
        for(int i = 0;i<4;i++){
            int ny = hy+d[i][0];
            int nx = hx+d[i][1];
            if(ny>=N||ny<0||nx>=N||nx<0)
                continue;
            if(visited[ny][nx])
                continue;
            if(board[ny][nx]=='1'){
                visited[ny][nx] = true;
                q.push({ny,nx});
            }
            
        }
    }
    answer.push_back(cnt);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>board[i];
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(board[i][j]=='1'&&!visited[i][j]){
                bfs(i,j);
            }
        }
    }
    sort(answer.begin(),answer.end());
    cout<<answer.size()<<"\n";
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i]<<'\n';
    }
}