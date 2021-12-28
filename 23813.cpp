#include <iostream>
using namespace std;
string s;
long long ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(int i = 0;i<s.size();i++){
        char a = s.back(); s.pop_back();
        s.insert(s.begin(),a);
        ans+=stoi(s);
    }
    cout<<ans;
}