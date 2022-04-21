#include <iostream>
using namespace std;
bool s[2005];
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        s[a+1000] = true;
    }
    for(int i = 0;i<2005;i++){
        if(s[i])
            cout<<(i-1000)<<" ";
    }
}