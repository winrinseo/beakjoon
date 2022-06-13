#include <iostream>
using namespace std;
int d[105][105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>d[i][j];
    
    for(int i = 0;i<n;i++)
        for(int j=0;j<m;j++){
            int a;cin>>a;
            d[i][j]+=a;
        }
     for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
     }    
}