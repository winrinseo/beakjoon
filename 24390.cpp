#include <iostream>
#include <string>
#define INF 987654321
using namespace std;
string a;
int N;
int dp[3650][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    N = stoi(a.substr(0,2))*60+stoi(a.substr(3,2));
    for(int i = 0;i<2;i++)
        for(int j = 0;j<3650;j++)
            dp[j][i] = INF;
    dp[0][0] = 0;
    dp[30][1] = 1;
    for(int i = 1;i<=N;i++){
        if(i>=10) {
            dp[i][0] = min(dp[i][0],dp[i-10][0]+1);
            dp[i][1] = min(dp[i][1],dp[i-10][1]+1);
        }
            
        if(i>=60) {
            dp[i][0] = min(dp[i][0],dp[i-60][0]+1);
            dp[i][1] = min(dp[i][1],dp[i-60][1]+1);
        }
        
        if(i>=600) {
            dp[i][0] = min(dp[i][0],dp[i-600][0]+1);
            dp[i][1] = min(dp[i][1],dp[i-600][1]+1);
        }

        if(i>=10) dp[i][1] = min(dp[i][1],dp[i][0]+1);
        if(i>=30) dp[i][1] = min(dp[i][1],dp[i-30][1]+1);
    }
    cout<<min(dp[N][0]+1,dp[N][1]);
}