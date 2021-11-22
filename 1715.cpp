#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    priority_queue<int> q;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        q.push(-a);
    }
    int answer = 0;
    while(q.size()!=1){
        int a = -q.top();q.pop();
        int b = -q.top();q.pop();
        answer+=(a+b);
        q.push(-(a+b));
    }
    cout<<answer;
}