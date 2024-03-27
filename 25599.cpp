#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int dp[2005][2005][11];
ll N,R;
bool solve(int k){
    ll exp = 0;
    int _log = (int)log2(k);
    int p = pow(2,_log);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            exp += max(max(dp[i][j][_log],dp[i+k-p][j][_log]),max(dp[i][j+k-p][_log],dp[i+k-p][j+k-p][_log]));
            if(R <= exp) return true;
        }
    }
    return false; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>R;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            cin>>dp[i][j][0];
    int c = 1;
    for(int k = 1;k<=10;k++){
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                dp[i][j][k] = max(max(dp[i][j][k-1],dp[i+c][j][k-1]),max(dp[i][j+c][k-1],dp[i+c][j+c][k-1]));
            }
        }
        c*=2;
    }

    int answer = -1;
    int lo = 1 , hi = N;
    while(lo<=hi){
        int mid = (lo+hi)/2;

        if(solve(mid)){
            hi = mid - 1;
            answer = mid;
        }else{
            lo = mid+1;
        }
    }
    cout<<answer;
}