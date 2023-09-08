#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> p;
int dp[100005];
bool solve(int t){

    for(int i = 0;i<=N+1;i++){
        dp[i] = 0;
    }

    for(int i = 0;i<p.size();i++){
        int st = max(p[i] - t , 0);
        int ed = min(p[i] + t , N);
        dp[st] += 1;
        dp[ed] -= 1;
        
    }

    for(int i = 0;i<N;i++){
        
        if(i > 0){
            dp[i] += dp[i-1];
        }
        if(i<=N && dp[i] == 0) return false;
        
    }
    
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    for(int i = 0;i<M;i++){
        int a;cin>>a;
        p.push_back(a);
    }

    int lo = 1 , hi = N+1;
    int answer = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;

        if(solve(mid)){
            hi = mid-1;
            answer = mid;
        }else{
            lo = mid+1;
        }
    }
    cout<<answer;
}