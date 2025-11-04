#include <iostream>
#include <queue>

using namespace std;

int N,K;

int A[5005];
bool visited[5005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;


    for(int i = 0;i<N;i++)
        cin>>A[i];

    
    queue<int> q;
    q.push(0);

    visited[0] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == N-1){
            cout<<"YES";
            return 0;
        }

        for(int i = cur + 1;i<N;i++){
            int k = (i - cur) * (1 + abs(A[cur] - A[i]));

            if(visited[i]) continue;
            if(k > K) continue;
            visited[i] = true;
            q.push(i);
        }
    }
    cout<<"NO";
}