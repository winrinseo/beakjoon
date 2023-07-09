#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
priority_queue<int> pq,mpq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++){
        int a;cin>>a;
        if(a > 0) pq.push(a);
        else mpq.push(-a);
    }
    int ans = 0;
    while(pq.size() > 1){
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();
        ans += max(a+b,a*b);
    }
    if(!pq.empty()) ans += pq.top();
    while(mpq.size() > 1){
        int a = -mpq.top();mpq.pop();
        int b = -mpq.top();mpq.pop();
        ans += max(a+b,a*b);
    }

    if(!mpq.empty()) ans += -mpq.top();
    cout<<ans;
}