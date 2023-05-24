#include <iostream>
#include <string>

using namespace std;
string p;
int dp[2005];
int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>p;

    for(int i = 0;i<p.size();i++){
        if(p[i] == 'a'){
            dp[i + 1] = 1;
            dp[i + 1 + p.size()] = 1;
            cnt++;
        }
    }

    for(int i = 1; i<=p.size() * 2; i++){
        dp[i] += dp[i-1];
    }
    int m = 10000;
    for(int i = cnt; i <= p.size() * 2; i++){
        int acnt = dp[i] - dp[i-cnt];
        m = min(m , cnt - acnt);
    }
    cout<<m;
}