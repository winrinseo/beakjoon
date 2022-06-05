#include <iostream>
using namespace std;
int M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M;
    int n = 0;

    for(int i = 0;i<M;i++){
        string a;
        int b;
        cin>>a;
        if(a!="all"&&a!="empty"){
            cin>>b;
            if(a=="add") n |= (1<<b);
            else if(a=="remove") n &= ~(1<<b);
            else if(a=="check") {
                bool ss = (n & (1<<b))>0?1:0;
                cout<<ss<<"\n";
            }
            else if(a=="toggle") n ^= (1<<b);
            
        }
        else if(a=="all") n |= ~0;
        else if(a=="empty") n = 0;
        
    }
}