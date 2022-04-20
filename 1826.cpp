#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
using namespace std;
int N;
int dst,r;
vector<pii> board;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> pq;
    cin>>N;
    for(int i = 0;i<N;i++){
        int a,b;cin>>a>>b;
        board.push_back({a,b});
    }
    sort(board.begin(),board.end());
    cin>>dst>>r;
    if(r>=dst){
        cout<<0;
        return 0;
    }
    int cnt = 0;
    int i = 0;
    while(dst > r){
        //현재 위치에서 갈 수 있는 주유소를 모두 큐에 삽입
        while(r>=board[i].first && i<board.size()){
            pq.push(board[i].second);
            i++;
        }
        if(pq.empty()){
            cout<<-1;
            return 0;
        }
        r+= pq.top();pq.pop();
        cnt++;
        if(r>=dst){
            cout<<cnt;
            return 0;
        }

        
    }
    
}