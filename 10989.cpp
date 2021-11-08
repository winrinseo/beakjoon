#include <iostream>
#include <algorithm>
using namespace std;
int N;
int d[10005];
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        int a; cin>>a;
        d[a]++;
    }
    for(int i = 0;i<10005;i++){
        for(int j = 0;j<d[i];j++){
            cout<<i<<"\n";
        }
    }
    
}