#include <iostream>
#include <algorithm>
using namespace std;
long long x,y;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>x>>y;
    long long z = (y*100)/x;
    long long answer = INT64_MAX;
    long long lo = 0,hi = 1000000000;
    while(lo<=hi){
        long long mid = (lo+hi)/2;
        long long r = (y+mid)*100/(x+mid);
        if(z < r){
            answer = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    if(answer==INT64_MAX) cout<<-1;
    else cout<<answer;
}