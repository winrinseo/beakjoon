#include <iostream>
using namespace std;
int N;
int d[25];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    d[0] = 0,d[1] =1;
    for(int i = 2;i<=N;i++){
        d[i] = d[i-1]+d[i-2];
    }
    cout<<d[N];
}