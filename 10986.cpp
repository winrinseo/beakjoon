#include <iostream>

using namespace std;
int N,M;
long long p[1000005];
long long num[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    num[0]++;
    for(int i = 1;i<=N;i++){
        cin>>p[i];
        p[i] += p[i-1];
        p[i] %= M;
        num[p[i]]++;
    }
    long long answer = 0;
    for(int i = 0;i<1005;i++){
        answer += num[i]*(num[i]-1)/2;
    }
    cout<<answer;
}