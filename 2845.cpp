#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin>>N>>K;
    for(int i = 0;i < 5;i++){
        int a;cin>>a;
        cout<<a-(N*K)<<" ";
    }
}