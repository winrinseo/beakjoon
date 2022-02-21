#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while(cin>>N){
        int aa = 0;
        for(int i = 1;;i++){
            aa = aa*10+1;
            aa%=N;
            if(aa==0){
                cout<<i<<"\n";
                break;
            }
        }
    }
}