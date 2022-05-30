#include <iostream>
using namespace std;
int r,c;
int N,M;
int a,d;
int dir[2] = {-1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    cin>>a>>d;
    cin>>r>>c;
    int hr=1,hc=a;
    while(1){
        
        if(r==hr&&c==hc){
            cout<<"NO...";
            return 0;
        }
        if(hr==N&&hc==M){
            cout<<"YES!";
            return 0;
        }
        if(hc+dir[d]>=1&&hc+dir[d]<=M) hc+=dir[d];
        if(r==hr&&c==hc){
            cout<<"NO...";
            return 0;
        }
        if(hr==N&&hc==M){
            cout<<"YES!";
            return 0;
        }
        if(hc<=1||hc>=M){
            hr+=1;
            d+=1;d%=2;
        }
        
    }
    
}