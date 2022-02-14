#include <iostream>
using namespace std;
int n;
int main(){

    cin>>n;
    int a = 0;
    int ss = 1;
    for(int i = 1;;i++){
        ss+=a;
        if(ss>=n){
            cout<<i;
            return 0;
        }
        a+=6;
    }
}