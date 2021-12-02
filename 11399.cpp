#include <iostream>
#include <queue>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> pq;
    cin>>N;
    for(int i = 0;i<N;i++){
        int a; cin>>a;
        pq.push(-a);
    }
    int sum = 0;
    int answer = 0;
    while(!pq.empty()){
        int a = -pq.top(); pq.pop();
        sum += a;
        answer+=sum;
    }
    cout<<answer;
}