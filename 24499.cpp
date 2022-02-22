#include <iostream>

using namespace std;
int N,K;
int p[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i = 0;i<N;i++)
        cin>>p[i];
    for(int i = N;i<2*N;i++){
        p[i]=p[i-N];
    }
    int sum = 0;
    for(int i = 0;i<K;i++)
        sum+=p[i];
    int answer = sum;
    for(int i = K;i<2*N;i++){
        sum+=p[i];
        sum-=p[i-K];
        answer = max(answer,sum);
    }
    cout<<answer;
}