#include <iostream>
#include <algorithm>
#define pii pair<long long,long long>
using namespace std;
int N;
pii arr[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>arr[i].first;
    for(int i = 0;i<N;i++)
        cin>>arr[i].second;

    sort(arr,arr+N,[](pii& a,pii& b){
        return a.second < b.second;
    });
    long long ans = 0;

    int lo = 0,hi=0;
    long long prev = 0;
    long long seg = 0;
    while(hi < N){
        if(arr[lo].second < arr[hi].second){
            lo = hi;
            prev = seg;
            seg = 0;
            
        }else if(arr[lo].second == arr[hi].second){
            if(max(prev , arr[hi].second) > arr[hi].first){
                long long rest = max(prev , arr[hi].second) - arr[hi].first;
                int day = 0;
                day += rest / 30;
                if(rest % 30 > 0) day++;
                seg = max(seg,30*day+arr[hi].first);
                ans += day;
            }else{
                seg = max(seg,arr[hi].first);
            }
            
            hi++;
        }
    }
    cout<<ans;
}