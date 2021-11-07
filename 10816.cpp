#include <iostream>
#include <map>
using namespace std;
int N,M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int,int> hash;
    cin>>N;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        hash[a]++;
    }
    cin>>M;
    for(int i = 0;i<M;i++){
        int a;cin>>a;
        cout<<hash[a]<<" ";
    }
}