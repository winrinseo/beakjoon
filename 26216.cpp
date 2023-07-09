#include <iostream>
#include <queue>
using namespace std;
int N;
priority_queue<int> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++){
        int a;cin>>a;
        pq.push(a);
    }
    int ans = 0;
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += b;
        pq.push(a-b);
    }
    ans += pq.top();
    if(ans > 1440) cout<<-1;
    else cout<<ans;
}