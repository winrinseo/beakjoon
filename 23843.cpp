#include <iostream>
#include <queue>
#include <algorithm>
using ll = long long;
int N,M;
ll c[11];
using namespace std;
/*int min_value(){
    ll a = (INT64_MAX-1);
    int idx;
    for(int i = 0;i < M;i++){
        if(a > c[i]){
            a = c[i];
            idx = i;
        }
    }
    return idx;
}*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    /*priority_queue<ll> pq;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        pq.push(a);
    }
    while(!pq.empty()){
        ll curr = pq.top();pq.pop();
        int idx = min_value();
        c[idx]+=curr;
    }
    ll answer = -1;
    for(int i = 0;i<M;i++) answer = max(answer,c[i]);
    cout<<answer;*/
    priority_queue<ll> pq;
    priority_queue<ll> c;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        pq.push(a);
    }
    for(int i = 0;i<M;i++) c.push(0);
    while(!pq.empty()){
        ll curr = pq.top();pq.pop();
        ll cc = -c.top();c.pop();
        c.push(-(cc+curr));
    }
    while(c.size()!=1) c.pop();
    cout<<-c.top();
}