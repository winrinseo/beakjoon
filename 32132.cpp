#include <iostream>


using namespace std;
int N;
string str;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    cin>>str;

    int flag = 0;

    for(int i = 0;i<str.size();i++){
        if(str[i] == 'P') flag = 1;
        else if(flag == 1 && str[i] == 'S') flag = 2;
        else if(flag == 2 && (str[i] == '4' || str[i] == '5'))
            continue;
        else flag = 0;
        
        s.push_back(str[i]);
    }

    cout<<s;
}