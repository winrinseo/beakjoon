#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed;
    cout.precision(6);
    double sum=0,hs=0;
    for(int i = 0;i<20;i++){
        string a,c;
        double b;cin>>a>>b>>c;
        double s;
        if(c[0]=='P') continue;
        if(c[0]=='A') s = 4.0;
        if(c[0]=='B') s = 3.0;
        if(c[0]=='C') s = 2.0;
        if(c[0]=='D') s = 1.0;
        if(c[0]=='F') s = 0.0;
        if(c[0]!='F'&&c[1]=='+') s+=0.5;
        sum+=(b*s);
        hs+=b;
    }
    cout<<sum/hs;
}