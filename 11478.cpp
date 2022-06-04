#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set<string> a;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;

    for(int i = 0;i<s.size();i++){
        string ss;
        for(int j = i;j<s.size();j++){
            ss.push_back(s[j]);
            a.insert(ss);
        }
    }
    cout<<a.size();
}