#include <iostream>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int N,Q;
int board[64][64];
int temp[64][64];
bool melting_ice[64][64];
int level[7];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
void rotate(int x,int y,int k,int n){
    if(k==n){
        for(int i = 0;i<level[k];i++)
            for(int j = 0;j<level[k];j++)
                temp[i+y][j+x] = board[y+level[k]-1-j][i+x]; 
    }else{
        int size = level[n-1];
        rotate(x,y,k,n-1);
        rotate(x,y+size,k,n-1);
        rotate(x+size,y,k,n-1);
        rotate(x+size,y+size,k,n-1);
    }
}
void melt(){
    for(int i = 0;i < level[N];i++){
        for(int j = 0;j < level[N];j++){
            melting_ice[i][j] = false;
            if(board[i][j]<=0) continue;
            int cnt = 0;
            for(int z = 0;z<4;z++){
                int nr = i+d[z][0];
                int nc = j+d[z][1];
                if(nr<0||nr>=level[N]||nc<0||nc>=level[N])
                    continue;
                if(board[nr][nc] > 0)
                    cnt++;
            }
            if(cnt < 3) melting_ice[i][j] = true;
        }
    }

    for(int i = 0;i < level[N];i++)
        for(int j = 0;j < level[N];j++)
            if(melting_ice[i][j]) board[i][j]--;

}
int answer[2] = {0,0};
bool visited[64][64];
int bfs(int r,int c){
    queue<pii> q;
    q.push({r,c});
    visited[r][c] =true;
    int ret = 0;
    while(!q.empty()){
        pii cur = q.front();q.pop();
        ret++;
        for(int i = 0;i<4;i++){
            int nr = cur.first+d[i][0];
            int nc = cur.second+d[i][1];
            if(nr<0||nr>=level[N]||nc<0||nc>=level[N])
                continue;
            if(!visited[nr][nc]&&board[nr][nc]!=0){
                visited[nr][nc] = true;

                q.push({nr,nc});
            }
        }
    }
    return ret;
}
void print(){
    for(int i = 0;i<level[N];i++){
        for(int j = 0;j<level[N];j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i = 0;i<7;i++)
        level[i] = 1<<i;
    for(int i = 0;i<level[N];i++){
        for(int j = 0;j<level[N];j++){
            cin>>board[i][j];
        }
    }
    for(int q = 0;q<Q;q++){
        int a;cin>>a;

        rotate(0,0,a,N);
        for(int i = 0;i<level[N];i++)
            for(int j = 0;j<level[N];j++)
                board[i][j] = temp[i][j];
        melt();
    }
    for(int i = 0;i<level[N];i++){
        for(int j = 0;j<level[N];j++){
            answer[0]+=board[i][j];
            if(!visited[i][j]&&board[i][j]!=0){
                answer[1] = max(answer[1],bfs(i,j));
            }
        }
    }
    
    cout<<answer[0]<<"\n"<<answer[1];
}