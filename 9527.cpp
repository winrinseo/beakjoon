#include <iostream>
#include <cmath>

#define ll long long

using namespace std;
ll A,B;
ll dp[62];
ll solve(ll x){
    if(x<=0) return 0;
    if(x==1) return 1;
    int n = (int)log2(x);
    ll rt = 1LL<<n;
    ll ret = 0;
    
    for(int i = 0;i<n;i++)
        ret+=dp[i];
    

    return (ll)ret + (x-rt+1) + solve(x-rt);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 1;
    for(int i = 1;i<62;i++){
        dp[i] = (1LL<<i);
        for(int j = 0;j<i;j++){
            dp[i]+=dp[j];
        }
    }
    cin>>A>>B;
    cout<<(ll)solve(B)-solve(A-1);
}