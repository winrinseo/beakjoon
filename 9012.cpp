#include <iostream>
#include <stack>
using namespace std;
int N;
bool isValid(string str){
    stack<char> s;
    for(int i = 0;i<str.size();i++){
        if(str[i]=='('){
            s.push('(');
        }else{
            if(s.empty()) return false;
            s.pop();
        }
    }
    if(!s.empty()) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>N;
    for(int i = 0;i<N;i++){
        string str;cin>>str;
        if(isValid(str)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}