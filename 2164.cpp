#include <iostream>
#include <queue>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    queue<int> q;
    for(int i = 1;i<=N;i++)
        q.push(i);
    
    while(q.size() != 1){
        q.pop();
        int c = q.front();
        q.push(c); q.pop();
    }
    cout<<q.front();
}