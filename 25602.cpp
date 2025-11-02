#include <iostream>

using namespace std;

int N,K;
int A[10];
int R[10][10],M[10][10];

int Msolve(int cur){
    if(cur == K)
        return 0;
    int ret = 0;
    for(int i = 0;i<N;i++){
        if(A[i] > 0){
            A[i]--;
            ret = max(ret , Msolve(cur + 1) + M[cur][i]);
            A[i]++;
        }
    }
    return ret;
}
int solve(int cur){
    if(cur == K)
        return Msolve(0);
    int ret = 0;
    for(int i = 0;i<N;i++){
        if(A[i] > 0){
            A[i]--;
            ret = max(ret , solve(cur + 1) + R[cur][i]);
            A[i]++;
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;

    for(int i = 0;i<N;i++)
        cin>>A[i];

    for(int i = 0;i<K;i++)
        for(int j = 0;j<N;j++)
            cin>>R[i][j];
     
    for(int i = 0;i<K;i++)
        for(int j = 0;j<N;j++)
            cin>>M[i][j];
    

    cout<<solve(0);
}