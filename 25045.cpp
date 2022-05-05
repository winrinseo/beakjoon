#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int N,M;
ll a[200005],b[200005];
bool cmp(ll& a,ll& b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 0 ;i<N;i++)
        cin>>a[i];
    
    for(int i = 0;i<M;i++)
        cin>>b[i];

    int size = min(N,M);
    sort(a,a+N,cmp);
    sort(b,b+M);
    ll answer = 0;
    for(int i = 0;i<size;i++){
        ll sum = a[i]-b[i];
        if(sum < 0) break;
        answer+=sum;
    }
    cout<<answer;
}