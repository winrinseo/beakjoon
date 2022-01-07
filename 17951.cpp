#include <iostream>
#include <algorithm>
using namespace std;
int N,K;
int p[100005];
int answer = -1;
int mkg(int m){
    int g = 0,res = 0;
    int minv = INT32_MAX;
    for(int i =0;i < N; i++){
        res += p[i];
        if(res >= m){
            g++;
            minv = min(minv,res);
            res = 0;
        }
    }
    minv = min(minv,res);
    if(g==K) answer = max(answer,minv);
    return g;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    int total = 0;
    for(int i = 0;i < N; i++){
        cin>>p[i];
        total +=p[i];
    }
    //그룹당 최소 인원을 mid명으로 제한했을 때 그룹의 수 k
    int lo = 1,hi = total;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int cnt = mkg(mid);
        if(K > cnt){
            hi = mid-1;
        }else if(K <= cnt){
            lo = mid+1;
        }
    }
    cout<<lo-1;
}