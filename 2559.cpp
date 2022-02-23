#include <iostream>
#include <algorithm>
using namespace std;
int N,K;
int p[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i = 0;i<N;i++)
        cin>>p[i];
    
    int sum = 0;
    
    for(int i = 0;i<K;i++)
        sum += p[i];
    int best = sum;

    for(int i = K;i<N;i++){
        sum+=p[i];
        sum-=p[i-K];
        best = max(best,sum);
    }
    cout<<best;
}