#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool isfel(string a){
    for(int i =0;i<=a.size()/2;i++){
        if(a[i]!=a[a.size()-1-i])
            return false;
    }
    return true;
}
int main(){
    while(1){
        string s; cin>>s;
        if(s=="0") break;
        if(isfel(s))
            cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
    }

}