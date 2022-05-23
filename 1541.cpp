#include <iostream>
#include <vector>
using namespace std;
string s;
vector<string> split(string a){
    string d;
    vector<string> ret;
    bool flag = true;
    for(int i = 0;i<a.size();i++){

        if(a[i]=='-'||a[i]=='+'){
            char del = flag? '+':'-';
            ret.push_back(del+d);
            d.clear();
            flag = a[i]=='-'?false:true;
        }else{
            d.push_back(a[i]);
        }
    }
    char del = flag? '+':'-';
    ret.push_back(del+d);
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    bool flag = false;
    for(int i = 0;i<s.size();i++){
        if(!('0'<=s[i]&&s[i]<='9')){
            if(flag&&s[i]=='+') s[i] = '-';
            if(s[i]=='-') flag = true;
        }
    }
    vector<string> r = split(s);
    int answer = stoi(r[0]);
    for(int i = 1;i<r.size();i++){
        answer+=stoi(r[i]);
    }
    cout<<answer;
}