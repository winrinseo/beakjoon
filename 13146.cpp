#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;
stack<int> s;
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll answer = 0;
    int maxs = 0;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        maxs = max(maxs,a);
        if(s.empty())
            s.push(a);
        else{
            if(s.top() < a){
                int t = s.top();
                s.pop();
                answer+=a-t;
                s.push(a);
            }else if(s.top() > a){
                s.pop();
                s.push(a);
            }
        }
    }
    while(!s.empty()){
        ll t = s.top();s.pop();
        answer += maxs-t;
    }
    
    cout<<answer;
}