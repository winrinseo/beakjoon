#include <iostream>
#include <string>
#include <stack>

using namespace std;
int N;
int num[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>num[i];
    }
    stack<int> s;
    string res;
    int idx = 0;
    for(int i = 1;;){
        if(idx>=N) break;
        if(s.empty() || s.top() < num[idx]){
            s.push(i);
            cout<<i<<" ";
            res.push_back('+');
            i++;
        }else if(s.top()==num[idx]){
            s.pop();
            res.push_back('-');
            idx++;
        }else{
            res.clear();
            break;
        }
    }
    if(res.empty()){
        cout<<"NO";
    }else{
        for(int i =0;i<res.size();i++)
            cout<<res[i]<<'\n';
    }

}