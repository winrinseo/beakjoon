#include <iostream>
#include <stack>

using namespace std;

string n;
int N;

stack<char> l, r;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    for(int i = 0;i<n.size();i++){
        l.push(n[i]);
    }

    cin>>N;

    for(int i = 0;i<N;i++){
        char a , b;

        cin>>a;

        if(a == 'L'){
            if(!l.empty()){
                r.push(l.top());
                l.pop();
            }
        }else if(a == 'D'){
            if(!r.empty()){
                l.push(r.top());
                r.pop();
            }
        }else if(a == 'B'){
            if(!l.empty()){
                l.pop();
            }
        }else{
            cin>>b;
            l.push(b);
        }
    }

    while(!l.empty()){
        r.push(l.top());
        l.pop();
    }
    while(!r.empty()){
        cout<<r.top();
        r.pop();
    }
    
}