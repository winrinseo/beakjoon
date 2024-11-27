#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;

int N,W,L;

queue<int> ready;
queue<pii> bridge;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>W>>L;


    for(int i = 0;i<N;i++){
        int a; cin>>a;

        ready.push(a);
    }

    int ans = 0;
    int total = 0;
    do{
        ans++;
        //다리에서 나올 수 있는지 확인
        if(!bridge.empty()){
            if(bridge.front().second + W == ans){
                total -= bridge.front().first;
                bridge.pop();
            }
        }

        //진입 가능한지 확인
        if(!ready.empty()){
            if(total + ready.front() <= L){
                bridge.push({ready.front() , ans});
                total += ready.front();
                ready.pop();
            }
        }
        
    }while(!bridge.empty() );

    cout<<ans;
}