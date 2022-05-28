#include <iostream>
#include <queue>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++){
        int a;cin>>a;
        priority_queue<int> q;
        if(a==0){
            if(q.empty()) cout<<0<<"\n";
            else {
                cout<<q.top()<<"\n";
                q.pop();
            }

        }else{
            q.push(a);
        }
    }
}