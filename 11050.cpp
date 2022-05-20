#include <iostream>
using namespace std;
int n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;

    if(k==0) cout<<1;
    else{
        int a = 1;
        for(int i = n;i>n-k;i--)
            a*=i;
        int b = 1;
        for(int i = 1;i<=k;i++)
            b*=i;
        cout<<a/b;
    }
}