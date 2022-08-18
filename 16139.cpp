#include <iostream>
using namespace std;
string s;
int Q;
int dp[26][200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(int i = 0;i<s.size();i++)
        for(int k = 0;k<26;k++)
            dp[k][i+1] = s[i]-'a' == k ? dp[k][i]+1:dp[k][i];
        
    cin>>Q;
    for(int i = 0;i<Q;i++){
        char c;cin>>c;
        int a,b;cin>>a>>b;
        cout<<dp[c-'a'][b+1] - dp[c-'a'][a]<<"\n";
    }
}