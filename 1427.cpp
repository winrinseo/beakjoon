#include <iostream>
#include <algorithm>
using namespace std;
string a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    sort(a.begin(),a.end(),[](char& a,char& b){
        return a-'0'> b-'0';
    });
    cout<<a;
}