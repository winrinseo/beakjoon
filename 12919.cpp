#include <iostream>
#include <algorithm>
using namespace std;

string a,b;

void dfs(string s){
    if(a == s){
        cout<<1;
        exit(0);
    }
    if(a.size() == s.size())
        return;

    if(s[0] == 'B'){
        string ss = s;
        reverse(ss.begin() , ss.end());
        ss.pop_back();
        dfs(ss);
    }

    if(s[s.size() - 1] == 'A'){
        string ss = s;
        ss.pop_back();
        dfs(ss);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>a>>b;

    dfs(b);
    cout<<0;
}