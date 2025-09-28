#include <iostream>
#include <algorithm>
using namespace std;

int H , W;
int m[2][15][15];
int dp[15][15];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>H>>W;

    for(int k = 0;k<2;k++){
        for(int i = 0;i<H;i++){
            for(int j = 0;j<W;j++){
                cin>>m[k][i][j];
            }
        }
    }
    int answer = 1000000000;
    
        
        
    for(int i = 0; i<H;i++){
        for(int j = 0;j<W;j++){
            dp[i][j] = (m[0][i][j] - m[1][i][j]) * (m[0][i][j] - m[1][i][j]);
        }
    }
    for(int i = 1; i<H;i++){
        for(int j = 0;j<W;j++){
            dp[i][j] = min(
                {
                    dp[i - 1][max(0 , j - 1)] , 
                    dp[i - 1][j] , 
                    dp[i - 1][min(W - 1 , j + 1)]
                }) + dp[i][j];
        }
    }
    for(int i = 0;i<W;i++){
        answer = min(answer , dp[H-1][i]);
    }


    cout<<answer;
}