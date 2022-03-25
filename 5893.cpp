#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;
string a;
string s;
string bsum(string& a,string& b){
    if(a.size() < b.size()) swap(a,b);
    string ret;
    int next = 0;
    for(int i = 0;i<b.size();i++){
        int sum = next+(a[i]-'0')+(b[i]-'0');
        if(sum>=2){
            if(sum==3) ret.push_back('1');
            if(sum==2) ret.push_back('0');
            next = 1;
        }else if(sum){
            ret.push_back('1');
            next = 0;
        }else{
            ret.push_back('0');
        }
    }
    //올림수와의 합
    for(int i = b.size();i<a.size();i++){
        int sum = next+(a[i]-'0');
        if(sum==2){
            ret.push_back('0');
        }else if(next){
            ret.push_back('1');
            next = 0;
        }else{
            ret.push_back(a[i]);
        }
    }
    if(next) ret.push_back('1');
    return ret;
}
int main(){
    cin>>a;
    reverse(a.begin(),a.end());
    int num = 17;
    while(num){
        s.push_back((num%2)+'0');
        num/=2;
    }
    string z = "0000"+a;
    string answer = bsum(a,z);
    // for(int i = 0;i<s.size();i++){
    //     if(s[i]=='1') {
    //         string z;
    //         for(int j = 0;j<i;j++) z.push_back('0');
    //         string concat = z+a;
    //         answer = bsum(answer,concat);
    //     }
    // }
    for(int i = answer.size()-1;i>=0;i--)
        cout<<answer[i];
}