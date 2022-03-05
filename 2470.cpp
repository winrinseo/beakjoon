#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[100005];
int answer[2];
int dist = INT32_MAX;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>p[i];
    sort(p,p+N);
    for(int i = 0;i < N-1;i++){
        int lo = i+1,hi = N-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(abs(p[i]+p[mid]) < dist){
                dist = abs(p[i]+p[mid]);
                answer[0] = p[i];
                answer[1] = p[mid];
            }
            if(p[i]+p[mid] > 0){
                hi = mid-1;
            }else if(p[i]+p[mid] < 0){
                lo = mid+1;
            }else{
                cout<<p[i]<<" "<<p[mid];
                return 0;
            }
            
        }
    }
    
    cout<<answer[0]<<" "<<answer[1];
}