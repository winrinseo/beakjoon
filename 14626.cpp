#include <iostream>

using namespace std;

string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>s;

    int a = 0;
    int idx = -1;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '*') {
            idx = i;
            continue;
        }
        
        if(i % 2 == 1){
            a += ((s[i] - '0') * 3);
        }else{
            a += (s[i] - '0');
        }
        
    }

    if(idx % 2 == 0){
        if(a % 10 == 0)
            cout<<0;
        else cout<<10 - (a % 10);
    }else{
        for(int i = 0; i<=9;i++){
            if((a + (i * 3)) % 10 == 0){
                cout<<i;
                return 0;
            }
        }
    }

}