#include <iostream>
using namespace std;
int T,N,M;
long long dp[35][35];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>M;
        //nCr = nCn-r
        if(M-N < N) N = M-N;
        long long a = 1;
        long long b = 1;
        for(int i=0;i<N;i++){
            a *= (M-i);
            b *= (i+1);
        }
        cout<<(long long)a/b<<"\n";
    }
}