#include <iostream>
#define mod 1000000
#define ll long long
using namespace std;
ll N;
ll dp[3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //피사노 주기의 길이 P
    //구하고자 하는 것, N%P 번째 수열을 mod연산한 것 
    //주기의 길이 P , mod = 10^k (k>2)일 때, P = 15*10^(k-1)
    cin>>N;
    int P = 15*100000;
    N %= P;
    dp[0] = 0,dp[1] = 1;
    for(int i = 2;i<=N;i++){
        dp[i%3] = (dp[(i-1)%3]+dp[(i-2)%3])%mod;
    }
    cout<<dp[N%3];

}