#include <iostream>
using namespace std;
int N;
int p[1005];
int dp[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>p[i];
    for(int i = 0;i<N;i++) dp[i] = p[i];
    for(int i = 1;i<N;i++){
        for(int j = 0;j<i;j++){
            if(p[j]<p[i]){
                dp[i] = max(dp[i],dp[j]+p[i]);
            }
        }
    }
    int answer = 0;
    for(int i = 0;i<N;i++)
        answer = max(answer,dp[i]);
    cout<<answer;
}