#include <iostream>
using namespace std;
int T,a,b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>a>>b;
        int c = a;
        if(a%10==0) {
            cout<<10<<"\n";
            continue;
        }
        for(int i = 0;i<b-1;i++){
            if(a > 10) a %= 10;
            a*=c;
        }
        if(a > 10) a%=10;
        cout<<a<<"\n";
    }
}