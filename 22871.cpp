#include <iostream>
#include <queue>

using namespace std;

int N;
int A[5005];
bool visited[5005];
bool check(long long K){
    for(int i = 0;i<N;i++)
        visited[i] = false;
    
    queue<int> q;

    q.push(0);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == N-1) return true;
        for(int next = cur + 1;next<N;next++){
            long long k = (long long)(next - cur) * (1 + abs(A[next] - A[cur]));
            if(visited[next]) continue;
            if(k <= K){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++){
        cin>>A[i];
    }


    long long lo = 1 , hi = (1LL<<40);
    
    while(lo <= hi){
        long long mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
        }else {
            lo = mid + 1;
        }
    }
    cout<<lo;
}