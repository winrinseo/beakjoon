#include <iostream>
#include <algorithm>
using namespace std;
long long p[1000005];
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>p[i];
    long long answer = max(p[0],p[N-1]);
    for(int i = 1;i<N-1;i++){
        answer = max(answer,p[i]+min(p[i-1],p[i+1]));
    }
    cout<<answer;
}