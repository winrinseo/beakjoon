#include <iostream>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        int a; cin>>a;
        if((a&(-a))==a) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}