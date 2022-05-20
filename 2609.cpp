#include <iostream>
using namespace std;
int A,B;
int gcd(int a,int b){
    while(a % b){
        int t = b;
        b = a % b;
        a = t;
    }
    return b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    int s = gcd(A,B);
    int ss = (A*B)/s;
    cout<<s<<"\n"<<ss;
}