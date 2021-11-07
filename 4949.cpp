#include <iostream>
#include <stack>
using namespace std;
bool isValid(string str){
    stack<char> p;
    for(int i = 0;i<str.size();i++){
        switch(str[i]){
            case '(':
                p.push('(');
                break;
            case '{':
                p.push('{');
                break;
            case '[':
                p.push('[');
                break;
            case ')':
                if(p.empty()||p.top()!='(')
                    return false;
                p.pop();
                break;
            case '}':
                if(p.empty()||p.top()!='{')
                    return false;
                p.pop();
                break;
            case ']':
                if(p.empty()||p.top()!='[')
                    return false;
                p.pop();
                break;
        }
    }
    if(!p.empty()) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        string str;
        getline(cin,str);
        if(str==".") break;
        if(isValid(str))
            cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
    }
}