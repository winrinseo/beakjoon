#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
string sel[100005][2];
int dp[100005][3];//2 : 스킵이 아직 남아있을때 1 : 스킵이 남아있지 않을 때
// 0 : 해당 위치에서 스킵할때
int cal(int i,string& a){
    if(a[0]=='+')
        return i+(a[1]-'0');
    else if(a[0]=='-')
        return i-(a[1]-'0');
    else if(a[0]=='*')
        return i*(a[1]-'0');
    else return i/(a[1]-'0');
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1;i<=N;i++){
        for(int j = 0;j<2;j++){
            cin>>sel[i][j];
        }
    }
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for(int i = 1;i<=N;i++){
        if(dp[i-1][2]>0||dp[i-1][1]>0)
            dp[i][2] = max(cal(dp[i-1][2],sel[i][0]),cal(dp[i-1][2],sel[i][1]));
        
        if(dp[i-1][1]>0||dp[i-1][0]>0)
            dp[i][1] = max(max(cal(dp[i-1][1],sel[i][0]),cal(dp[i-1][1],sel[i][1])),
                        max(cal(dp[i-1][0],sel[i][0]),cal(dp[i-1][0],sel[i][1])));
        if(dp[i-1][2] > 0) dp[i][0] = dp[i-1][2];
        else dp[i][0] = -1;
        if(max(dp[i][0],max(dp[i][1],dp[i][2]))<=0) {
            cout<<"ddong game";
            return 0;
        }
        
    }
    cout<<max(dp[N][0],max(dp[N][1],dp[N][2]));
}