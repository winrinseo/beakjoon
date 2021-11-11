#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 5
#define INF 9876543219876
using namespace std;
int N;
int board[1005][1005];
long long dist[7][1005][1005];//출발지 //0 = 부대
vector<pair<int,int>> chase;
pair<int,int> src;
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
struct Point{
    long long cost;
    int r,c;
};
struct cmp{
    bool operator()(Point& a,Point& b){
        return a.cost > b.cost;
    }
};
void dij(int num,pair<int,int> st){
    priority_queue<Point,vector<Point>,cmp> pq;
    dist[num][st.first][st.second] = 0;
    pq.push({0,st.first,st.second});
    while(!pq.empty()){
        Point curr = pq.top();pq.pop();
        for(int i = 0;i<4;i++){
            int nr = curr.r+d[i][0];
            int nc = curr.c+d[i][1];
            if(nr<0||nr>=N||nc<0||nc>=N)
                continue;
            int nextcost = curr.cost;
            if(board[nr][nc] > 0)
                nextcost += board[nr][nc];
            if(dist[num][nr][nc] > nextcost){
                dist[num][nr][nc] = nextcost;
                pq.push({nextcost,nr,nc});
            }
        }
    }
}
long long solve(int curr,int state){
    if(state==(1<<chase.size())-1){
        //탈영병을 모두 다 잡았으면 부대로 돌아간 후 종료
        return dist[curr][src.first][src.second];
    }
    long long ret = INF;
    for(int i = 0;i<chase.size();i++){
        if(state&(1<<i)) continue;
        ret = min(ret,
            solve(i+1,state|(1<<i))+dist[curr][chase[i].first][chase[i].second]);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]==0){
                chase.push_back({i,j});
            }    
            if(board[i][j] == -1)
                src = {i,j};
            
        }
    }
    for(int i = 0;i<7;i++)
        for(int j = 0;j<1005;j++)
            for(int z = 0;z<1005;z++)
                dist[i][j][z] = INF;
    dij(0,src);
    for(int i = 0;i<chase.size();i++){
        dij(i+1,chase[i]);
    }
    cout<<solve(0,0);
}