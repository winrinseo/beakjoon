#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int p[105];
int answer = 0;
void solve(int idx,int n,int a){
    if(a > M) return;
    else if(n == 0){
        answer = max(answer,a);
        return;
    }
    if(idx>=N) return;
    solve(idx+1,n-1,a+p[idx]);
    solve(idx+1,n,a);
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0 ;i<N;i++){
        cin>>p[i];
    }
    solve(0,3,0);
    cout<<answer;
}