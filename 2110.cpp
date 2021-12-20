#include <iostream>
#include <algorithm>
#define MAX 1000000000
using namespace std;
int N,C;
int h[200005];
bool solve(int dist){
    int cur = 0;
    int a = 1;

    while(1){
        int next = h[cur]+dist;
        int* dd = lower_bound(h,h+N,next);
        if(dd==(h+N)) break;
        cur = dd-h;
        a++;
        if(a==C) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>C;
    for(int i = 0;i<N;i++)
        cin>>h[i];
    sort(h,h+N);
    int lo = 1, hi = MAX;
    int answer = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(solve(mid)){
            lo = mid+1;
            answer = mid;
        }else{
            hi = mid-1;
        }
    }
    cout<<answer;
}