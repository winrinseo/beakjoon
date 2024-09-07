#include <iostream>

using namespace std;


long long X , K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>X>>K;

    long long Y = (1LL << 63) - 1;

    Y = X ^ Y;
    long long temp = Y;
    
    for(int i = 0 ;i<32;i++){
        if((K & (1<<i)) != 0){
            int s = 0;
            for(int j = 0;j<63;j++){
                if((Y & (1LL<<j)) != 0){
                    if(s == i){
                        temp ^= (1LL<<j);
                        break;
                    }
                    s++;
                }
            }
        }
    }
    
    Y ^= temp;
    cout<<Y;

}