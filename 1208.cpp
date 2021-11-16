#include <iostream>
#include <map>
#define W 4000000

using namespace std;
int N,S;
int arr[45];
long long h[8000010];
long long res = 0;
void left(int cur,int sum){
    if(cur>N/2){
        h[sum+W]++;
        return;
    }
    left(cur+1,sum+arr[cur]);
    left(cur+1,sum);
    return;
}
void right(int cur,int sum){
    if(cur==N){
        if(h[S-sum+W]>0){
            res+=h[S-sum+W];
        }
        return;
    }
    right(cur+1,sum+arr[cur]);
    right(cur+1,sum);
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>S;
    for(int i = 0;i < N;i++){
        cin>>arr[i];
    }
    left(0,0);
    right(N/2+1,0);
    if(S==0) res-=1;
    cout<<res;  
}