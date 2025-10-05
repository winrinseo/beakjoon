#include <iostream>

using namespace std;

int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    int ans = (N / 18) * 2;

    N %= 18;
    if(N == 0) cout<<ans;
    else if(N < 10) cout<<ans + 1;
    else if(N % 2 == 0) cout<<ans + 2;
    else cout<<ans + 3;
}