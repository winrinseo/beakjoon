#include <iostream>
#include <deque>

using namespace std;
int N;
deque<char> dq;
deque<bool> f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        int cmd;cin>>cmd;
        char a;
        if(cmd == 1){
            cin>>a;
            dq.push_back(a);
            f.push_back(0);
        }else if(cmd == 2){
            cin>>a;
            dq.push_front(a);
            f.push_back(1);
        }else{
            if(dq.empty()) continue;
            if(!f.back()) dq.pop_back();
            else dq.pop_front();
            f.pop_back();
        }
    }

    if(dq.empty()){
        cout<<0;
        return 0;
    }
    while(!dq.empty()){
        cout<<dq.front();dq.pop_front();
    }
}