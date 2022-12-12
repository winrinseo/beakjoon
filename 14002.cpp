#include <iostream>
#include <vector>
using namespace std;
int N;
int p[1005],dp[1005],track[1005];
int maxL = 0,idx = -1;
vector<int> ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1;i <= N;i++){
        cin>>p[i];
        dp[i] = 1;
    }
    
    for(int i = 1;i<=N;i++){
        for(int j = 1;j < i; j++){
            if(p[j] < p[i]){
                if(dp[i] < dp[j] + 1){
                    track[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(maxL < dp[i]){
            maxL = dp[i];
            idx = i;
        }
    }

    for(int i = idx; i != 0; i = track[i]){
        ans.push_back(p[i]);
    }
    cout<<maxL<<"\n";
    for(int i = ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";

    
}