#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
vector<string> map;
vector<vector<bool>> visited;
int d[2][2] = {{0,1},{1,0}};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++){
        string str;
        cin>>str;
        map.push_back(str);
    }
    visited = vector<vector<bool>>(N , vector<bool>(N));
    queue<pair<int,int>> q; 
    q.push({0,0});
    visited[0][0] = 1;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.first == N-1 && cur.second == N-1){
            cout<<"Yes";
            return 0;
        }
        for(int i = 0;i<2;i++){
            int nr = cur.first + d[i][0];
            int nc = cur.second + d[i][1];
            if(nr >= N || nc >= N)
                continue;

            if(map[nr][nc] == 'x')
                continue;

            if(visited[nr][nc])
                continue;
            
            q.push({nr,nc});
            visited[nr][nc] = 1;
        }
    }
    cout<<"No";
}