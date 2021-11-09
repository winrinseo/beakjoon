#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++) cin>>p[i];
    sort(p,p+N);
    for(int i = 0;i<N;i++) cout<<p[i]<<"\n";
}