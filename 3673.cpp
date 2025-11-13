#include <iostream>
#include <memory.h>
using namespace std;

int T;
int D,N;
long long mod[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>D>>N;
        int prefixsum = 0;
        long long answer = 0;
        for(int i = 0;i<D+1;i++)
            mod[i] = 0;
        
        mod[0] = 1;
        for(int i = 0;i<N;i++){
            int a;cin>>a;
            prefixsum += a;
            prefixsum %= D;
            answer += mod[prefixsum];
            mod[prefixsum]++;
        }
        cout<<answer<<'\n';
    }
}