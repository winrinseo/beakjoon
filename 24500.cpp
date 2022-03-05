#include <iostream>
using ll = long long;
using namespace std;
ll N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll c = 1;
    while(c < N) c <<= 1;
    if(N==1) cout<<1<<"\n"<<(ll)N;
    else if(N==c){
        cout<<2<<"\n"<<(ll)N-1<<"\n"<<(ll)N;
    }else if(N==c-1){
        cout<<1<<"\n"<<(ll)N;
    }else{
        c = ~(c-1);
        ll n = ~N;
        c = c^n;
        cout<<2<<"\n"<<(ll)c<<"\n"<<(ll)N;
    }
}