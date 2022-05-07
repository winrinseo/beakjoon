#include <iostream>
#define ll long long
using namespace std;
string s;
ll check = 0;
int p(int cur){
    int ret = 0;
    for(int i = cur;i<s.size();i++){
        if(check&1LL<<i) continue;
        check |= 1LL<<i;
        if(s[i]=='('){
            ret += (s[i-1]-'0')*p(i+1)-1;
        }else if(s[i] == ')') break;
        else ret++;
    }
    return ret;
}
int main(){
    cin>>s;
    cout<<p(0);
}