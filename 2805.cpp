#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int wood[1000005];

bool isValid(int h){
    int get = 0;
    for(int i = 0;i<N;i++){
        if(wood[i] > h) get += (wood[i] - h);
        if(get >= M) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 0;i<N;i++) cin>>wood[i];
    
    int lo = 0,hi = 1000000000;
    int answer = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(isValid(mid)){
            answer = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    cout<<answer;
}