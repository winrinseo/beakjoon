#include <iostream>

using namespace std;

string s;
bool check[505];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>s;

    int zero = 0 , one = 0;

    for(int i = 0;i<s.size();i++){
        if(s[i] == '1') one++;
        else zero++;
    }

    one /= 2; zero /= 2;

    for(int i = 0;i<s.size();i++){
        if(one == 0) break;

        if(s[i] == '1'){
            check[i] = 1;
            one--;
        }
    }

    for(int i = s.size() - 1; i >= 0; i--){
        if(zero == 0) break;

        if(s[i] == '0'){
            check[i] = 1;
            zero--;
        }
    }

    for(int i = 0;i<s.size();i++){
        if(check[i]) continue;
        cout<<s[i];
    }
    
}