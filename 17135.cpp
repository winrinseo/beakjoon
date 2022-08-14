#include <iostream>
#include <queue>
#include <vector>
#define e pair<int,int>
using namespace std;
int N,M,D;
vector<int> com;
int answer = 0;
int board[20][20];
vector<e> enemy;
int num = 0;
int solve(){
    int nn = 0;
    int n = 0;
    int d = 0;
    queue<int> q[20];
    for(int j = 0;j<M;j++){
        for(int i = N-1;i>=0;i--){
            if(board[i][j]){
                q[j].push(i);
                nn++;
            }
         }
    }
    while(nn){
        int shoot[3] = {-1,-1,-1};
        for(int i = 0;i<3;i++){
            int ee = 100000000;
            int idx = -1;
            for(int j = 0;j < M;j++){
                while(!q[j].empty() && q[j].front()+d >= N) {q[j].pop();nn--;}
                if(q[j].empty()) continue;
                int dist = abs(N - (q[j].front()+d)) + abs(com[i] - j);

                if(dist <= D){
                    if(ee > dist){
                        ee = dist;
                        idx = j;
                    }
                }
            }
            shoot[i] = idx;
        }
        if(nn == 0) break;
        bool check[300] = {0};
        for(int i = 0;i<3;i++){
            if(shoot[i]==-1) continue;
            if(!check[shoot[i]]){
                check[shoot[i]] = true;
                n++;
                nn--;
                q[shoot[i]].pop();
            }
        }
        d++;
    }
    return n;
}
void comb(int cnt,int m){
    if(m==0){
        int a = solve();
        answer = max(answer,a);
        return;
    }
    if(cnt == M) return;

    for(int i = cnt;i<M;i++){
        com.push_back(i);
        comb(i+1,m-1);
        com.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>D;

    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++){

            cin>>board[i][j];
            if(board[i][j] == 1) num++;
        }
    comb(0,3);
    cout<<answer;
}