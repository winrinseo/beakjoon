#include <iostream>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin>>N;
    int answer = N;
    if(N==0){
        cout<<1;
        return 0;
    }
    while(--N){
        answer*=N;
    }
    cout<<answer;
}