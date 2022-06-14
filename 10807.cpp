#include <iostream>
using namespace std;
int N;
int p[205];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        p[a+100]++;
    }
    int b;cin>>b;
    cout<<p[b+100];
}