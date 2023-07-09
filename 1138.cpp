#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N;
int info[15];

stack<int> s,ds;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 1;i<=N;i++)
        cin>>info[i];
    

    for(int i = N;i>=1;i--){

        while(!s.empty() && s.size() > info[i]){
            ds.push(s.top());
            s.pop();
        }
        s.push(i);

        while(!ds.empty()){
            s.push(ds.top());
            ds.pop();
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());s.pop();
    }

    for(int i = N-1;i>=0;i--)
        cout<<ans[i]<<" ";

}