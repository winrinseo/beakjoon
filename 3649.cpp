#include <iostream>
#include <algorithm>
using namespace std;
int X,N;
int b[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>X>>N;
        if(cin.eof())break;
        X *= 10000000;
        for(int i = 0;i < N;i++){
            cin>>b[i];
        }
        sort(b,b+N);
        int gap = -1;
        int alo=-1,ahi=-1;
        for(int i = 0;i < N-1;i++){
            int lo = i+1,hi = N-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(b[i]+b[mid] > X){
                    hi = mid-1;
                }else if(b[i]+b[mid] < X){
                    lo = mid+1;
                }else{
                    if(gap < abs(b[i]-b[mid])){
                        gap = abs(b[i]-b[mid]);
                        alo = b[i] , ahi = b[mid];
                    }
                    hi = mid-1;
                }
            }
        }
        if(gap==-1) cout<<"danger"<<"\n";
        else cout<<"yes "<<alo<<" "<<ahi<<"\n";
    }
    
}