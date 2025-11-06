#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;

int M;
bool visited[3][10005];
vector<pii> v;
int d[8][2] = {{-1,-1} , {-1,1} , {1,1},{1,-1},{-1,-2},{1,-2},{-1,2},{1,2}};
void solve(pii cur , int cnt){
    if(cnt == M * 2){
        cout<<"YES"<<"\n";
        for(auto & [y,x] : v){
            cout<<y<<" "<<x<<"\n";
        }
        exit(0);
    }

    for(int i = 0;i<8;i++){
        int nr = cur.first + d[i][0];
        int nc = cur.second + d[i][1];
        if(nr > 2 || nr < 1 || nc > M || nc < 1)
            continue;
        if(!visited[nr][nc]){
            visited[nr][nc] = 1;
            v.push_back({nr,nc});
            solve({nr,nc} , cnt + 1);
            v.pop_back();
            visited[nr][nc] = 0;
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M;

    // for(int i = 1;i<=2;i++){
    //     for(int j = 1;j<=M;j++){
    //         v.push_back({i,j});
    //         visited[i][j] = 1;
    //         solve({i,j},1);
    //         visited[i][j] = 0;
    //         v.pop_back();
    //     }
    // }

    v.push_back({1,1});
    visited[1][1] = 1;
    solve({1,1},1);
    
    cout<<"NO";
    return 0;
}