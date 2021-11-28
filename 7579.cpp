#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int dp[10005];
int c[105];
int w[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<N;i++) cin>>w[i];
    for(int i = 0;i<N;i++) cin>>c[i];

    for(int i = 0;i<N;i++){
        for(int j = 10004;j>=c[i];j--){
            //해당 비활성화 비용으로 확보 할 수 있는 메모리의 최대값
            dp[j] = max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    for(int i = 0;i < 10005;i++){
        if(dp[i]>=M){
            cout<<i;
            return 0;
        }
    }
}