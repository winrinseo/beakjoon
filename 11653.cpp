#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    int k = 2;
    while(N!=1){
        while(N%k==0){
            cout<<k<<"\n";
            N/=k;
        }
        k++;
    }
}