#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        int dp[10005] = {0}; 
        int c[5005] = {0};
        int w[5005] = {0};
        int N;
        double M;
        cin>>N>>M;
        if(N==0&&M==0.00) break;
        for(int i = 0;i<N;i++){
            cin>>c[i];
            double ww;cin>>ww;
            w[i] = (int)(ww*100+0.5);
        }
        int m = (int)(M*100+0.5);
        for(int i = 0;i<N;i++){
            for(int p = 0;p<=m;p++){
                if(p-w[i]>=0)
                    dp[p] = max(dp[p],dp[p-w[i]]+c[i]);
            }
        }
        
        sort(dp,dp+m);
        cout<<dp[m]<<"\n";
    }
    
}