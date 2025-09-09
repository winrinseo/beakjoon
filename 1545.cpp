#include <iostream>
#include <algorithm>

using namespace std;

string str;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;

    sort(str.begin(),str.end());

    int l = str.size()/2-1;
    int r = str.size()/2;
    if(str.size()%2 == 1) r++;

    for(;r<str.size();r++,l--){

        if(str[l] == str[r]){
            //가장 가깝고 큰 문자와 교체
            int idx = upper_bound(str.begin() + r + 1 , str.end() , str[r]) - str.begin();
            if(idx == str.size()){
                cout<<-1;
                return 0;
            }
            char temp = str[r];
            str[r] = str[idx];
            str[idx] = temp;
        }
    }

    cout<<str;
}