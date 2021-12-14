#include <iostream>
#include <stack>
using namespace std;
int N;
int answer[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    stack<pair<int,int>> s;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        while(!s.empty()&&s.top().first < a)
            s.pop();
        
        if(s.empty()) {
            answer[i] = 0;
            s.push({a,i+1});
        }else if(s.top().first > a){
            answer[i] = s.top().second;
            s.push({a,i+1});
        }
    } 
    for(int i =0;i<N;i++) cout<<answer[i]<<" ";
}