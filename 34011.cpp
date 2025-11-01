#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N;
int d[1000005] , depths[1000005];
vector<int> adj[1000005];

void dfs(int cur, int depth){
    depths[depth]++;
    for(int & next : adj[cur]){
        dfs(next , depth + 1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N-1;i++){
        int a;cin>>a;

        adj[a].push_back(i+2);
    }

    dfs(1 , 0);

    // 제동 거리가 k인 고양이
    for(int k = 2;k<=N;k++){
        // N/2 + N/3 .... + N/N
        // N (1/2 + 1/3 ... + 1/N) => N log(N);
        for(int i = k;i<=N;i+=k){
            d[k] += depths[i];
        }
    }

    int answer = 0;

    for(int i = 2;i<=N;i++){
        answer = max(answer , d[i] + 1);
    }
    cout<<answer;
}