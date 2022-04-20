#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;
int T;
int N,M;
int a[1005],b[1005];
unordered_map<int,ll> h;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>a[i];
        int sum = 0;
        for(int j = i;j>=0;j--){
            sum+=a[j];
            h[sum]++;
        }
    }
    ll answer = 0;
    cin>>M;
    for(int i = 0;i<M;i++){
        cin>>b[i];
        int sum = 0;
        for(int j = i;j>=0;j--){
            sum+=b[j];
            answer+=h[T-sum];
        }
    }
    cout<<answer;
}