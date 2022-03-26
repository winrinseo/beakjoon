#include <iostream>
using namespace std;
int N,M;
int broken = 0;
int cnt;
bool isvalid(int t){
    cnt = 0;
    if(t==0){
        cnt = 1;
        if(broken&1) return false;
        return true;
    }
    while(t){
        if(broken&1<<(t%10))
            return false;
        t/=10;
        cnt++;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a;cin>>a;
        broken |= (1<<a);
    }
    int answer = abs(N-100);
    for(int i = N;i>=0;i--){
        if(isvalid(i)){
            answer = min(answer,abs(N-i)+cnt);
        } 
    }
    for(int i = N+1;i<=N+499900;i++){
        if(isvalid(i)){
            answer = min(answer,abs(N-i)+cnt);
        } 
    }
    cout<<answer;
}