#include <iostream>
#include <algorithm>
using namespace std;
int N;
int a[55],b[55];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>a[i];    
    for(int i = 0;i<N;i++)
        cin>>b[i];

    sort(a,a+N,less<>());
    sort(b,b+N,greater<>());
    int answer = 0;

    for(int i = 0;i<N;i++){
        answer += (a[i]*b[i]);
    }
    cout<<answer;
}