#include <iostream>

using namespace std;
bool sw[105];
int N,M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1;i<=N;i++){
        cin>>sw[i];
    }
    cin>>M;
    for(int i = 0;i<M;i++){
        int a,b;cin>>a>>b;

        if(a==1){
            int r = b;
            while(r<=N){
                sw[r]^=1;
                r+=b;
            }
        }else{
            int r = 1;
            sw[b]^=1;
            while(1){
                if(b-r<1||b+r>N) break;
                if(sw[b-r]==sw[b+r]){
                    sw[b-r]^=1;
                    sw[b+r]^=1;
                    r++;
                }else break;
                
            }
        }
    }
    for(int i = 1;i<=N;i++){
        cout<<sw[i]<<" ";
        if(i%20==0) cout<<"\n";
    }
        
}