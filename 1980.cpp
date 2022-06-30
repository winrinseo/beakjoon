#include <iostream>
using namespace std;
int a,b,c;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c;
    int coke = 10001;
    int an = 0;
    for(int i = 0;;i++){
        if(a*i > c) break;
        int d = c-(a*i);
        int e = d/b;
        if(coke > d%b){
            coke = d%b;
            an = i+e;
        }else if(coke == d%b){
            an = max(an,i+e);
        }
    }
    cout<<an<<" "<<coke;
}