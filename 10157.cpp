#include <iostream>
using namespace std;
int N,M,a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N;
    cin>>a;
    int r = N,c = M;
    int delta = 1;
    int hr=0,hc=1;
    int cnt = 0;
    for(;;){
        
        for(int i = 0;i<r;i++){
            hr+=delta;
            ++cnt;
            if(cnt==a){
                cout<<hc<<" "<<hr;
                return 0;
            }
        }
        c--;
        if(c==0) break;
        for(int i = 0;i<c;i++){
            hc+=delta;
            ++cnt;
            if(cnt==a){
                cout<<hc<<" "<<hr;
                return 0;
            }
        }
        r--;
        if(r==0) break;
        delta*=-1;
    }
    cout<<0;
}