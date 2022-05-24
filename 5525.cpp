#include <iostream>
using namespace std;
int N,M;
string s;
int dp[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    cin>>s;
    int answer = 0;
    for(int i = 2;i<s.size();i++){
        if(s[i]=='I'&&s[i-1]=='O'&&s[i-2]=='I'){
            dp[i] = dp[i-2]+1;
            if(dp[i]>=N) answer++;
        }
    }
    cout<<answer;

}