#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N,M,K;
int A[15][15],board[15][15];
vector<int> wood[15][15];
queue<int> dead[15][15];
int d[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int k = 0;
bool cmp(int& a,int& b){
    return a > b;
}
void grow(int r,int c){
    int s = wood[r][c].size();
    queue<int> temp;
    sort(wood[r][c].begin(),wood[r][c].end(),cmp);
    while(!wood[r][c].empty()){
        int t = wood[r][c].back(); wood[r][c].pop_back();
        if(board[r][c] >= t){
            temp.push(t+1);
            board[r][c] -= t;
        }else dead[r][c].push(t);
    }
    while(!temp.empty()){
        wood[r][c].push_back(temp.front());
        temp.pop();
    }
    
}
void breed(int r,int c){
    int s = wood[r][c].size();
    queue<int> temp;
    while(!wood[r][c].empty()){
        int t = wood[r][c].back(); wood[r][c].pop_back();
        if(t % 5 ==0){
            for(int z = 0;z<8;z++){
                int nr = r+d[z][0], nc = c+d[z][1];
                if(nr<0||nr>=N||nc<0||nc>=N)
                    continue;
                wood[nr][nc].push_back(1);
            }
        }
        temp.push(t);
    }
    while(!temp.empty()){
        wood[r][c].push_back(temp.front());
        temp.pop();
    }
}
void spring(){
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            if(!wood[i][j].empty())
                grow(i,j);
}
void summer(){
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++){
            while(!dead[i][j].empty()){
                board[i][j] += (dead[i][j].front())/2;
                dead[i][j].pop();
            }
        }
}
void fall(){
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            breed(i,j);

}
void winter(){
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            board[i][j] += A[i][j];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin>>A[i][j];
            board[i][j] = 5;
        }
    }
    for(int i = 0;i<M;i++){
        int x,y,c;cin>>x>>y>>c;
        x--;y--;
        wood[x][y].push_back(c);
    }
    
    int season = 0;
    while(k!=K){
        //봄
        if(season == 0){
            spring();
        }else if(season == 1){//여름
            summer();
        }else if(season == 2){//가을
            fall();
        }else{//겨울
            winter();
        }   
        season++;
        if(season == 4){
            k++; season%=4;
        }
    }
    int answer = 0;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            answer += wood[i][j].size();
    cout<<answer;
}