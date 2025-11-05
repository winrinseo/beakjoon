#include <iostream>

using namespace std;

int D,K;
int dp[35];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>D>>K;

    dp[D] = K;

    //D + 1일의 떡의 수를 결정함
    for(int k = K + 1; k<=200000;k++){
        dp[D + 1] = k;
        bool flag = true;
        for(int i = D - 1;i>=1;i--){
            dp[i] = dp[i + 2] - dp[i + 1];
            if(dp[i] <= 0){
                flag = false;
                break;
            }
        }
        if(dp[1] > dp[2]) continue;
        if(flag){
            cout<<dp[1]<<"\n"<<dp[2];
            return 0;
        }
    }
}