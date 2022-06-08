#include <iostream>
using namespace std;
double a,b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    double s = (a*b)/100;
    if(a-s>=100) cout<<0;
    else cout<<1;
}