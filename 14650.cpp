#include <iostream>

using namespace std;

int N;

int ans;

int solve(int n){
    if(n == N){
        return (ans % 3 == 0);
    }

    int ret = 0;

    for(int i = 0;i<=2;i++){
        if(n == 0 && i == 0)
            continue;
        ans *= 10;
        ans += i;

        ret += solve(n+1);

        ans/=10;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    cout<<solve(0);
}