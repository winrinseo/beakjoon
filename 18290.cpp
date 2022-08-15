#include <iostream>

using namespace std;
int N,M,K;
int arr[15][15];
bool sel[15][15];
int solve(int r,int c,int k){
    if(k == 0) return 0;
    
    int ret = -100000000;

    for(int i = r;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(i==r && j < c) continue;
            if(!sel[i][j] && !sel[i-1][j] && !sel[i][j-1]){
                sel[i][j] = true;
                ret = max(ret,solve(i,j,k-1)+arr[i][j]);
                sel[i][j] = false;
            }
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>K;

    for(int i = 1;i<=N;i++) 
        for(int j = 1;j<=M;j++)
            cin>>arr[i][j];
    
    cout<<solve(1,1,K);
}