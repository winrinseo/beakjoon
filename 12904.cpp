#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string s,t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>t;
    while(t.size()!=1){
        if(t[t.size()-1]=='A'){
            t = t.substr(0,t.size()-1);
        }else if(t[t.size()-1]=='B'){
            reverse(t.begin(),t.end()-1);
            t = t.substr(0,t.size()-1);
        }
        if(t==s){
            cout<<1;
            return 0;
        }
    }
    if(t==s) cout<<1;
    else cout<<0;
}