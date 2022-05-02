#include <iostream>
using namespace std;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    string an;
    for(int i = s.size()-1;i>=0;i-=3){
        int c = 1;
        int a = 0;

        for(int j = i;j>=i-2;j--){
            if(j<0) break;
            if(s[j]=='1')
                a+=c;
            c*=2;
        }
        an.push_back(a+'0');
    }
    for(int i = an.size()-1;i>=0;i--)
        cout<<an[i];
}