#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;
int T,N,M;
char board[15][15];
int dp[MAX][1<<MAX];
bool isValid(int subset,int n,int prev){
    if(subset==0) return true;
    for(int i = 0;i<M;i++){
        if(subset&(1<<i)){
            if(board[n][i]=='x') return false;
            if(i!=0){
                if(prev&1<<(i-1)||subset&1<<(i-1))
                    return false;
            }

            if(i!=(M-1)){
                if(prev&1<<(i+1)||subset&1<<(i+1))
                    return false;
            }

        }
    }
    return true;
}
int solve(int n,int prev){
    if(n==N)
        return 0;
    //dp[n][prev] = 이전값이 prev일 때 row n에서의 최대값
    int &ret = dp[n][prev];
    //최대값이 0명일 수 있으므로 -1
    if(ret!=-1) return ret;
    ret = 0;
    int fullset = (1<<M)-1;
    for(int subset = fullset; subset != -1; subset-=1){
        if(isValid(subset,n,prev)){
            ret = max(ret,solve(n+1,subset)+__builtin_popcount(subset));
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        for(int i = 0;i<MAX;i++) fill(dp[i],dp[i]+(1<<MAX),-1);
        cin>>N>>M;
        for(int i = 0;i<N;i++)
            for(int j = 0;j<M;j++)
                cin>>board[i][j];

        cout<<solve(0,0)<<'\n';    

    }
}