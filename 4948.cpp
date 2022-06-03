#include <iostream>
using namespace std;
int N;
int a[250000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2;i<=246912;i++)
        a[i] = 1;
    
    for(int i = 2;i<=246912;i++){
        if(a[i]==0) continue;
        for(int j = 2*i;j<=246912;j+=i){
            a[j] = 0;
        }
    }
    for(int i = 1;i<=246912;i++)
        a[i] += a[i-1];

    while(1){
        cin>>N;
        if(N==0) break;
        cout<<a[2*N]-a[N]<<'\n';
    }
}