#include <iostream>
#include <algorithm>
using namespace std;
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        int N; cin>>N;
        int p[25] = {0};
        int dp[10005] = {0};
        for(int i = 0;i<N;i++){
            cin>>p[i];
        }
        int M; cin>>M;
        dp[0] = 1;
        for(int i = 0;i<N;i++){
            for(int j = 0; j <= M;j++){
                if(j-p[i]>=0){
                    dp[j] += (dp[j-p[i]]);
                }
            }
        }
        cout<<dp[M]<<"\n";
    }
}