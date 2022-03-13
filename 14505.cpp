#include <iostream>

using namespace std;
string s;
long long dp[1005][1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    s.resize(s.size()+1);
    for(int i = 0;i<s.size()-1;i++){
        dp[i][i] = 1;
        if(s[i]!=s[i+1]) //ab
            dp[i][i+1] = 2;
        else dp[i][i+1] = 3; //aa
    }

    for(int i = 2;i<s.size()-1;i++){

        for(int l = 0;l<s.size()-1;l++){
            int r = l+i;
            if(s.size()-1 < r) break;
            //dp[l+1][r-1] 구간은 두번 더해진 셈이기 때문에 한번 빼줌
            dp[l][r] = (dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]);
            //dp[l+1][r-1]의 팰린드롬에 앞 뒤로 같은 문자가 붙기때문에
            //dp[l+1][r-1] 개수만큼 팰린드롬이 다시생김 + s[l]s[r]
            if(s[l]==s[r])
                dp[l][r] += (dp[l+1][r-1]+1);
            
        }
    }
    cout<<dp[0][s.size()-2];
    
}