#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    deque<int> q;
    for(int i = 0; i < N; i++){
        string cmd; cin>>cmd;
        if(cmd=="push_front"){
            int a;cin>>a;
            q.push_front(a);
        }else if(cmd=="push_back"){
            int a;cin>>a;
            q.push_back(a);
        }else if(cmd=="pop_front"){
            if(q.empty()) cout<<-1<<"\n";
            else {
                cout<<q.front()<<"\n";
                q.pop_front();
            }
        }else if(cmd=="pop_back"){
            if(q.empty()) cout<<-1<<"\n";
            else {
                cout<<q.back()<<"\n";
                q.pop_back();
            }
        }else if(cmd=="size"){
            cout<<q.size()<<"\n";
        }else if(cmd=="empty"){
            cout<<q.empty()<<"\n";
        }else if(cmd=="front"){
            if(q.empty()) cout<<-1<<"\n";
            else cout<<q.front()<<"\n";
        }else{
            if(q.empty()) cout<<-1<<"\n";
            else cout<<q.back()<<"\n";
        }
    }
}