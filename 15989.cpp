#include <iostream>

using namespace std;

int T , N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;

    while(T--){

        cin>>N;
        int ans = 0;
        for(int i = 0; i<=N/3;i++){

            int a = N - (i * 3);
            ans += a/2+1;
        }
        cout<<ans<<"\n";
    }
}