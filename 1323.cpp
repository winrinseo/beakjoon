#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll N , K;
bool check[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    int n = N;
    ll e = 0;
    while(n){
        e++;
        n/=10;
    }
    ll m = pow(10LL , e);
    ll next = N % K;
    check[next] = true;
    int answer = 1;
    while(next != 0){
        next = (next * m + N) % K;
        if(check[next]){
            cout<<-1;
            return 0;
        }
        check[next] = true;
        answer++;
    }
    cout<<answer;
}