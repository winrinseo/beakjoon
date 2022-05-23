#include <iostream>
using namespace std;
int p[15][15];
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int i = 1;i<=14;i++)
        p[0][i] = i;
    
    for(int i = 1;i<=14;i++){
        for(int j = 1;j<=14;j++){
            p[i][j] = p[i][j-1]+p[i-1][j];
        }
    }
    while(T--){
        int a,b;cin>>a>>b;
        cout<<p[a][b]<<"\n";
    }
}