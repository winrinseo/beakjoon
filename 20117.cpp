#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N;
int d[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0 ;i<N;i++){
        cin>>d[i];
    }
    
    sort(d,d+N);

    deque<int> dq;

    for(int i = 0;i<N;i++)
        dq.push_back(d[i]);
    
    int answer = 0;
    while(dq.size() > 1){
        answer += (dq.back() * 2);
        dq.pop_back();
        dq.pop_front();
    }
    while(!dq.empty()){
        answer += dq.back();
        dq.pop_back();
    }
    cout<<answer;
}