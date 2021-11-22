#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a,b;
int F;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    F = 0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(a.size()<b.size()) swap(a,b);
    int s = b.size();
    int i = 0;
    string res;
    for(i = 0;i<s;i++){
        int p =(a[i]-'0')+(b[i]-'0')+F;
        res.push_back((p%10)+'0');
        F =p/10;
    }
    for(i = i;i<a.size();i++){
        int p =(a[i]-'0')+F;
        res.push_back((p%10)+'0');
        F = p/10;
    }
    if(F!=0) res.push_back(F+'0');
    for(int i = res.size()-1;i>=0;i--)
        cout<<res[i];
}