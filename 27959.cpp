#include <iostream>
using namespace std;
int N,M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    if(N * 100 >= M)
        cout<<"Yes";
    else cout<<"No";
}