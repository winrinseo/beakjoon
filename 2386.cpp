#include <iostream>

using namespace std;

string str;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(getline(cin,str)){
        if(str == "#") break;
        int answer = 0;
        char ch = str[0] | 32;
        for(int i = 1;i<str.size();i++){
            if(ch == (str[i] | 32)){
                answer++;
            }
        }
        cout<<str[0]<<" "<<answer<<"\n";
    }
}