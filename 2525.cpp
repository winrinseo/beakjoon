#include <iostream>

using namespace std;
int h,m,a;
int main(){
    cin>>h>>m>>a;
    m+=a;
    if(m>=60){
        h+=(m/60);
        m%=60;
    }
    if(h>=24){
        h%=24;
    }
    cout<<h<<" "<<m;
}