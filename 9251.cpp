#include <iostream>

using namespace std;
string a , b;

int dp[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;

    for(int i = 1;i<=a.size();i++){
        for(int j = 1;j<=b.size();j++){

            //지금까지 매칭된 최대 길이
            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);

            //해당 문자가 일치할 경우 일치된 문자 이전의 최대 길이 + 1
            if(a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j] , dp[i-1][j-1] + 1);

        }
    }
    cout<<dp[a.size()][b.size()];
}