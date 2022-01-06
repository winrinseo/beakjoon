#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int maxv = -1;
    int y,x;
    for(int i =1;i<=9;i++){
        for(int j = 1;j<=9;j++){
            int a;cin>>a;
            if(maxv<a){
                maxv = a;
                y=i,x=j;
            }
        }
    }
    cout<<maxv<<"\n";
    cout<<y<<" "<<x;
}