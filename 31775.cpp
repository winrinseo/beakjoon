#include <iostream>

using namespace std;

int flag;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;
    flag |= 1 << ('l' - 'a');
    flag |= 1 << ('p' - 'a');
    flag |= 1 << ('k' - 'a');

    for(int i = 0;i<3;i++){
        string a;cin>>a;

        answer |= 1 << (a[0] - 'a');
    }
    
    if(flag == answer){
        cout<<"GLOBAL";
    }else{
        cout<<"PONIX";
    }
}