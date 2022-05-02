#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;
int N,M;
bool visited[105][105];
bool board[105][105];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
queue<pii> st;
int bfs(){
    queue<pii> q;

    while(!st.empty()){
        pii a = st.front();st.pop();
        visited[a.first][a.second] = 1;
        q.push({a.first,a.second});
    }
    int ret = 0;
    while(!q.empty()){
        pii cur = q.front();q.pop();

        for(int i = 0;i<4;i++){
            int nr = cur.first+d[i][0];
            int nc = cur.second+d[i][1];
            if(nr<0||nr>N||nc<0||nc>M)
                continue;
            if(visited[nr][nc])
                continue;
            visited[nr][nc] = 1;
            if(board[nr][nc]){
                st.push({nr,nc});
                ret++;
            }else{
                q.push({nr,nc});
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int cs = 0;
    for(int i = 1;i<=N;i++)
        for(int j = 1;j<=M;j++){
            cin>>board[i][j];
            if(board[i][j]) cs++;
        }
    
    if(cs==0){
        cout<<0<<"\n"<<0;
    }
    st.push({0,0});
    st.push({0,M});
    st.push({N,0});
    st.push({N,M});
    int time = 1;
    while(1){

        int melt = bfs();
        cs-=melt;
        if(cs==0) {
            cout<<time<<"\n";
            cout<<melt;
            break;
        }
        time++;
    }
}