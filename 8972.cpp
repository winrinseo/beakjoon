#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;

int N,M;
string m[105];
int d[9][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,0},{0,1},{-1,-1},{-1,0},{-1,1}};
pii me;
vector<pii> enemy;
int enemy_lot[105][105];

int getDirection(pii k){
    int dist = 1000000000;
    int ret = -1;
    for(int i = 0;i<9;i++){
        int dd = abs(me.first - (k.first + d[i][0])) + abs(me.second - (k.second + d[i][1]));

        if(dist > dd){
            dist = dd;
            ret = i;
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 0;i<N;i++){
        cin>>m[i];

        for(int j = 0;j<M;j++){
            if(m[i][j] == 'I'){
                me = {i,j};
                m[i][j] = '.';
            }
            if(m[i][j] == 'R'){
                enemy.push_back({i,j});
                enemy_lot[i][j] = 1;
                m[i][j] = '.';
            }
        }
    }

    string order;
    cin>>order;
    
    for(int k = 0;k<order.size();k++){

        int cur_order = order[k] - '0' - 1;

        me = {me.first + d[cur_order][0], me.second + d[cur_order][1]};
        
        if(enemy_lot[me.first][me.second]){
            cout<<"kraj "<<k+1;
            return 0;
        }

        // 적 이동
        for(int i = 0;i<enemy.size();i++){
            if(enemy[i].first == -1) continue;
            int go = getDirection(enemy[i]);
            
            int nr = enemy[i].first + d[go][0];
            int nc = enemy[i].second + d[go][1];

            if(me.first == nr &&  me.second == nc){
                cout<<"kraj "<<k+1;
                return 0;
            }
            enemy_lot[nr][nc]++;
            enemy_lot[enemy[i].first][enemy[i].second]--;
            enemy[i] = {nr,nc};
        }

        // 적 중첩 확인
        for(int i = 0;i<enemy.size();i++){
            if(enemy[i].first == -1) continue;
            if(enemy_lot[enemy[i].first][enemy[i].second] >= 2){

                for(int j = i + 1;j<enemy.size();j++){
                    if(enemy[i].first == enemy[j].first && enemy[i].second == enemy[j].second){
                        enemy[j] = {-1,-1};
                    }
                }
                enemy_lot[enemy[i].first][enemy[i].second] = 0;
                enemy[i] = {-1,-1};
            }
        }
        
    }
    
    m[me.first][me.second] = 'I';
    for(int i = 0;i<enemy.size();i++){
        if(enemy[i].first == -1) continue;
        m[enemy[i].first][enemy[i].second] = 'R';
    }

    for(int i = 0;i<N;i++){
        cout<<m[i]<<'\n';
    }
}