#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
int N,K,L;
ll M[200005];
ll dp[400005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K>>L;

    for(int i = 0;i<N;i++)
        cin>>M[i];
    for(int i = 0;i<K;i++){
        int a;cin>>a;a--;
        dp[a] += 1;
        dp[a + L] += -1;
    }

    for(int i = 1;i<400005;i++){
        dp[i] += dp[i-1];
    }
    sort(M,M+N,[](ll& a,ll& b){
        return a > b;
    });
    sort(dp,dp+N,[](ll& a,ll& b){
        return a > b;
    });
    ll answer = 0;
    for(int i = 0;i<N;i++){
        answer += (M[i] / pow(2,dp[i]));
    }
    cout<<answer;
}