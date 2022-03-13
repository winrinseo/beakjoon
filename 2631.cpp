#include <iostream>
#include <algorithm>
using namespace std;
int p[205],dp[205];
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    for(int i = 0;i<N;i++)
        cin>>p[i];
    int lis = 1;
    for(int i = 0;i<N;i++){
        dp[i] = 1;
        for(int j = 0;j < i;j++){
            if(p[j] <= p[i]){
                dp[i] = max(dp[i],dp[j]+1);
                lis = max(lis,dp[i]);
            }
        }
    }
    cout<<N-lis;
}