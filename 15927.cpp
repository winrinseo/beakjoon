#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
bool a;
bool isPal(int l,int r){
    /*if(l==r||r+1==l) return true;
    if(str[l]!=str[r]) return false;
    return isPal(l+1,r-1);*/
    for(int i = 0;i<(r-l+1)/2;i++){
        if(str[l+i]!=str[r-i])
            return false;
        
        if(str[l+i]!=str[l+i+1]) a = true;;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    if(!isPal(0,str.size()-1)){
        cout<<str.size();
    }else{
        if(a) cout<<str.size()-1;
        else cout<<-1;
    }
}