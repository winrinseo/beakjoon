#include <iostream>
using namespace std;
char ff[14] = {'q','w','e','r','t','a','s','d','f','g','z','x','c','v'};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    string aa;cin>>aa;

    for(int i = 0;i<14;i++){
        if(aa.back()==ff[i]){
            cout<<1;
            return 0;
        }
    }
    cout<<0;
}