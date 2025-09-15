#include <iostream>

using namespace std;

int N,K;
int d[10];
bool visited[10];

int solve(int n , int cur){
    if(n == N) return 1;

    int ret = 0;
    for(int i = 0;i<N;i++){
        if(visited[i]) continue;
        if(cur + d[i] - K < 500) continue;
        visited[i] = 1;
        ret += solve(n + 1 , cur + d[i] - K);
        visited[i] = 0;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;

    for(int i = 0;i<N;i++)
        cin>>d[i];

    cout<<solve(0,500);
}