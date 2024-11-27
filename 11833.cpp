#include <iostream>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    
    cin>>N;

    int ans = 0;

    for(int i = 0;i<N;i++){
        cin>>a>>b;
        ans += (b%a);
    }
    cout<<ans;
}