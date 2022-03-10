#include <iostream>

using namespace std;
int N,M;
int p[1026][1026];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            int a;cin>>a;
            //p[i][j]는 두번 더해지는 셈이기 때문에 한번 빼줌
            p[i+1][j+1] = p[i+1][j]+p[i][j+1]-p[i][j]+a;
        }
    }
    for(int i = 0;i<M;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<p[x2][y2] - p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1]<<"\n";
    }
}