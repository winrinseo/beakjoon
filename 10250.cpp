#include <iostream>
using namespace std;
int T,H,W,P;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>H>>W>>P;
        int f = 0,r = 0,hand = -1;
        for(int i = 1;i<=P;i++){
            hand = (f+1)*100 + (r+1);
            f++;
            if(f >= H){
                f%=H;
                r++;
            }
        }
        cout<<hand<<"\n";
    }
}