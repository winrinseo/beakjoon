#include <iostream>
using namespace std;
int T;
int t[3] = {300,60,10};
int num[3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int i = 0;i<3;i++){
        num[i] = T/t[i];
        T%=t[i];
    }
    if(T) cout<<-1;
    else for(int i =0;i<3;i++) cout<<num[i]<<" ";
}