#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M,N;
int m[105];
int dp[15005];
vector<int> n[10005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N;

    for(int i = 1;i<=M;i++)
        cin>>m[i];

    for(int i = 0;i<N;i++){
        int a,b,c; cin>>a>>b>>c;
        n[i] = {a,b,c};
    }

    sort(n , n + N,[](vector<int> & a , vector<int> & b){
        if(a[1] == b[1])
            return a[0]<b[0];
        return a[1] < b[1];
    });
    int answer = 0;

    for(int i = 0; i<N;i++){
        for(int j = 0;j<=n[i][0];j++)
            dp[n[i][1]] = max(dp[n[i][1]] , dp[j] + ((n[i][1] - n[i][0]) * m[n[i][2]]));
        answer = max(dp[n[i][1]] , answer);
    }

    cout<<answer;
}