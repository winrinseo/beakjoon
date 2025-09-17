#include <iostream>

using namespace std;


int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    string str;
    
    while(cin>>str){
        
        string s;
        for(int i = 0;i<str.size();i+=2){
            if(i == str.size()-1) break;
            int c = ((str[i] - 'a') + (str[i+1] - 'a') - N + 26) % 26;
            s.push_back((c+'a'));
        }
        cout<<s<<' ';
    }
}