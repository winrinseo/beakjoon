#include <iostream>

using namespace std;

int T,N;
int dp[1005];

int gcd(int a , int b){
    if(a == 0 || b == 0)
        return 0;

    while(b){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    

    for(int i = 0; i<=1000;i++){
        for(int j = 0; j<=1000;j++){
            if(gcd(i,j) == 1){
                dp[max(i,j)]++;
            }
        }
    }
    dp[0] = 0 , dp[1] = 3;

    for(int i = 1;i<=1000;i++)
        dp[i] += dp[i-1];
    
    cin>>T;
    while(T--){
        cin>>N;
        cout<<dp[N]<<"\n";
    }
}