#include <iostream>
#include <queue>
using namespace std;
int N;
int m[200005];
priority_queue<int> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0; i<N;i++){
        cin>>m[i];
    }
    pq.push(-m[0]);

    int answer = 0;
    for(int i = 1;i<N;i++){
        answer = max(answer, m[i] + pq.top());
        pq.push(-m[i]);
    }
    cout<<answer;
}