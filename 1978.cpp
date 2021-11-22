#include <iostream>
using namespace std;
int N;
bool isprime(int a){
    if(a==0||a==1) return false;
    if(a==2) return true;
    for(int i = 2;i*i<=a;i++){
        if(a % i == 0)
            return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    int cnt = 0;
    for(int i =0;i<N;i++){
        int s;cin>>s;
        if(isprime(s)) cnt++;
    }
    cout<<cnt;
}