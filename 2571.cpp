#include <iostream>
#include <algorithm>
using namespace std;
int N;
int num[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>num[i];
    }
    sort(num,num+N);
    for(int i = 0;i<N;i++){
        cout<<num[i]<<"\n";
    }
}