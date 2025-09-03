#include <iostream>
#include <queue>
using namespace std;

int N,K;
bool arr[55];
priority_queue<int , vector<int>,greater<int>> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        if(!arr[a]){
            arr[a] = true;
        }else{
            pq.push(a);
        }
    }

    while(!pq.empty()){
        int k = 0;
        while(pq.top() + k <= N){
            if(!arr[pq.top() + k]){
                arr[pq.top() + k] = true;
                break;
            }
            k += K;
        }
        pq.pop();
    }

    for(int i = 1;i<=N;i++){
        if(!arr[i]){
            cout<<0;
            return 0;
        }
    }
    cout<<1;
}