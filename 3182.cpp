#include <iostream>
using namespace std;


int N;
int n[1005];
bool visited[1005];

int dfs(int cur , int p){
    if(visited[n[cur]]) return p;
    visited[cur] = 1;
    int ret = dfs(n[cur] , p + 1);
    visited[cur] = 0;
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 1;i<=N;i++){
        int a;cin>>a;

        n[i] = a;
    }

    int answer = 0;
    int m = 0;
    for(int i = 1;i<=N;i++){
        int d = dfs(i,1);
        if(m < d){
            m = d;
            answer = i;
        }
    }
    
    cout<<answer;
}