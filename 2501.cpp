#include <iostream>

using namespace std;

int N,K;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;
    int k = 0;
    for(int i = 1;i<=N;i++){
        if(N % i == 0){
            if(++k == K) {
                cout<<i;
                return 0;
            }
        }
    }

    if(k < K) cout<<0;
}