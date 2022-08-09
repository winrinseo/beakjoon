#include <iostream>

using namespace std;
int N;
int dp[1005],p[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++){
        dp[i] = 1;
        cin>>p[i];
    }
    int answer = 1;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<i;j++)
            if(p[j]<p[i]){
                dp[i] = max(dp[i],dp[j]+1);
                answer = max(answer,dp[i]);
            }
            
    cout<<answer;
    
}