#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;

string dp[3];
string sum(string& a,string& b){
    if(a.size()<b.size()) swap(a,b);
    int next = 0;
    string ret;
    for(int i = 0;i<b.size();i++){
        int h = (a[i]-'0')+(b[i]-'0')+next;
        next = h/10;
        ret.push_back((h%10)+'0');
    }
    for(int i = b.size();i<a.size();i++){
        int h = (a[i]-'0')+next;
        next = h/10;
        ret.push_back((h%10)+'0');
    }
    if(next!=0) ret.push_back(next+'0');
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    dp[0] = "0",dp[1]="1",dp[2]="1";
    for(int i = 3;i<=N;i++){
        dp[i%3] = sum(dp[(i-1)%3],dp[(i-2)%3]);
    }
    string & ret = dp[N%3];
    for(int i = ret.size()-1;i>=0;i--)
        cout<<ret[i];
}