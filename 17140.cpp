#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int R,C,K;
int board[105][105];
bool cmp(pii& a,pii& b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
void queryR(int r,int& size){
    vector<pii> v(105,{0,0});
    for(int i = 0;i<size;i++){
        v[board[r][i]].first = board[r][i];
        v[board[r][i]].second++;
    }
    sort(v.begin(),v.end(),cmp);
    int idx = 0;
    for(int i = 0;i<v.size();i++){
        if(idx == 100) break;
        if(v[i].first == 0) continue;
        if(v[i].second != 0){
            board[r][idx++] = v[i].first;
            board[r][idx++] = v[i].second;
        }
    }
    for(int i = idx;i<size;i++)
        board[r][i] = 0;
    size = max(size,idx);
}
void queryC(int c,int& size){
    vector<pii> v(105,{0,0});
    for(int i = 0;i<size;i++){
        v[board[i][c]].first = board[i][c];
        v[board[i][c]].second++;
    }
    sort(v.begin(),v.end(),cmp);
    int idx = 0;
    for(int i = 0;i<v.size();i++){
        if(v[i].first == 0) continue;
        if(idx == 100) break;
        if(v[i].second != 0){
            board[idx++][c] = v[i].first;
            board[idx++][c] = v[i].second;
        }
    }
    for(int i = idx;i<size;i++)
        board[i][c] = 0;
    size = max(size,idx);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C>>K;
    R--;C--;
    for(int i = 0;i<3;i++)
        for(int j = 0;j<3;j++)
            cin>>board[i][j];
    
    int ans = 0;
    int r = 3,c = 3;
    while(1){
        if(board[R][C] == K) break;
        if(r >= c){
            for(int i = 0;i<r;i++)
                queryR(i,c);
        }else{
            for(int i = 0;i<c;i++)
                queryC(i,r);
        }
        ans++;
        
        if(ans > 100){
            ans = -1;
            break;
        }
        
    }
    cout<<ans;
}