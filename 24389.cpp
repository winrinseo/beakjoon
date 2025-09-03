#include <iostream>
using namespace std;
int N,M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    M = ~N;
    M += 1;

    

    int answer = 0;
    for(int i = 0;i<32;i++){
        if((N & 1) != (M & 1)){
            answer++;
        }
        N>>=1;
        M>>=1;
    }

    cout<<answer;

}