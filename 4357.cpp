#include <iostream>

using namespace std;

int N,M;
int m[10][10];
bool check[10][10];
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int solve(int id){

    int ret = 0;

    int i = id / M;
    int j = id % M;

    if(i >= N || i < 0 || j >= M || j < 0)
        return 0;
    
            
    for(int k = 0;k<4;k++){
        int nr[2] = {i + d[k][0] , i + d[(k+1)%4][0]};
        int nc[2] = {j + d[k][1] , j + d[(k+1)%4][1]};
                
        if(nr[0] >= N || nr[0] < 0 || nc[0] >= M || nc[0] < 0)
            continue;
                
        if(nr[1] >= N || nr[1] < 0 || nc[1] >= M || nc[1] < 0)
            continue;
                
        if(check[nr[0]][nc[0]] || check[nr[1]][nc[1]] || check[i][j])
            continue;

        check[i][j] = check[nr[0]][nc[0]] = check[nr[1]][nc[1]] = 1;
        ret = max(ret , solve(id+1) + (m[i][j] * 2) + m[nr[0]][nc[0]] + m[nr[1]][nc[1]]);
        check[i][j] = check[nr[0]][nc[0]] = check[nr[1]][nc[1]] = 0;
    }

    ret = max(ret , solve(id+1));

    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
            cin>>m[i][j];

    cout<<solve(0);
}