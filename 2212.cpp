#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,K;
int m[10005];
priority_queue<int> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;
    for(int i = 0;i<N;i++){
        cin>>m[i];
    }

    sort(m , m+N);
    for(int i = 1;i<N;i++){
        pq.push(m[i] - m[i-1]);
    }
    // 기지국을 하나만 설치했을 때
    int answer = m[N-1] - m[0];
    
    K--;

    while(!pq.empty() && K--){
        // 가장 비용이 많이 들어가는 구간을 끊어서 그룹을 하나씩 더 늘림
        answer -= pq.top();
        pq.pop();
    }

    cout<<answer;
    
}