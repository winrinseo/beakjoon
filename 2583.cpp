#include <iostream>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
bool board[105][105];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int Y,X,K;
int bfs(int r,int c){
    queue<pii> q;
    q.emplace(r,c);
    board[r][c] = 1;
    int ret = 1;
    
    while(!q.empty()){
        pii cur = q.front();q.pop();
        for(int i = 0;i<4;i++){
            int nr = cur.first+d[i][0];
            int nc = cur.second+d[i][1];
            if(nr<0||nr>=Y||nc<0||nc>=X)
                continue;
            if(!board[nr][nc]){
                ret++;
                board[nr][nc] = 1;
                q.emplace(nr,nc);
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>Y>>X>>K;

    for(int k = 0;k<K;k++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i = y1;i<y2;i++){
            for(int j = x1;j<x2;j++){
                board[i][j] = 1;
            }
        }
    }
    int answer = 0;
    vector<int> ans;
    for(int i = 0;i<Y;i++){
        for(int j = 0;j<X;j++){
            if(!board[i][j]){
                answer++;
                ans.push_back(bfs(i,j));
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<answer<<"\n";
    for(int a:ans)
        cout<<a<<" ";
}