#include <iostream>
#define INF 987654321
using namespace std;

int N,K;
int arr[100005];
int dp[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;
    
    for(int i = 0;i<100005;i++){
        dp[i] = INF;
    }

    for(int i = 1;i<=N;i++){
        cin>>arr[i];
    }

    dp[0] = 0;
    
    int k = 0;
    for(int i = 1;i<=N;i++){

        for(int j = 1;j<=3;j++){
            if(i - j >= 0) dp[i] = min(dp[i] , dp[i - j] + 1);
        }

        if(i > 1 && abs(arr[i] - arr[i-1]) == 1) k++;
        else k = 1;
        
        if(k >= K){
            dp[i] = min(dp[i] , dp[i - K] + 1);
        }
    }

    cout<<dp[N];
}