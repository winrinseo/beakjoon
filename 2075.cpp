#include <iostream>
#include <queue>
using namespace std;


int N;
priority_queue<int,vector<int> , greater<int>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N*N;i++){
        int a;cin>>a;
        if(pq.size() >= N){
            if(a < pq.top()) continue;
            else pq.pop();
        }
        pq.push(a);
    }

    
    cout<<pq.top();
}