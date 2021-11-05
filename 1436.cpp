#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
string itos(int i){
    string ret;
    while(i){
        ret.push_back((i%10)+'0');
        i/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
bool isValid(int i){
    string num = itos(i);
    for(int it = 1;it < num.size()-1;it++){
        if(num[it-1]=='6'&&num[it]=='6'&&num[it+1]=='6')
            return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int seq = 0;
    for(int i = 666;;i++){
        if(isValid(i)){
            if(N == ++seq){
                cout<<i;
                break;
            }  
        }
    }
}