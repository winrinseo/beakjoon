#include <iostream>

using namespace std;

int T;

int main(){
    cin>>T;

    while(T--){
        string a;
        int b;
        cin>>a>>b;

        int a0 = a[0] - 'A';
        int a1 = a[1] - '0' - 1;
        b--;

        int b0 = b / 8;
        int b1 = b % 8;

        if(a0 % 2 == b0 % 2){
            if(a1 % 2 == b1 % 2){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
        }else{
            if(a1 % 2 != b1 % 2){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
        }
        
    }
}