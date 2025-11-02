#include <iostream>

using namespace std;

string str;
string p = "PPAP";
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    string s;
    for(int i = 0;i<str.size();i++){
        s.push_back(str[i]);

        if(s.size() >= 4){
            bool flag = true;

            for(int j = 0; j < 4;j++){
                if(s[s.size() - 4 + j] != p[j])
                    flag = false;
            }

            if(flag){
                for(int j = 0;j<4;j++)
                    s.pop_back();
                s.push_back('P');
            }
        }
    }

    if(s.size() == 1 && s[0] == 'P'){
        cout<<"PPAP";
    }else cout<<"NP";
}