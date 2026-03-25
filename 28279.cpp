#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;


    while(N--){
        int a,b;
        cin>>a;

        if(a == 1){
            cin>>b;
            dq.push_front(b);
        }else if(a == 2){
            cin>>b;
            dq.push_back(b);
        }else if(a == 3){
            
            if(dq.empty()) cout<<-1;
            else{
                cout<<dq.front();
                dq.pop_front();
            }
            cout<<"\n";
        }else if(a == 4){
            
            if(dq.empty()) cout<<-1;
            else{
                cout<<dq.back();
                dq.pop_back();
            }
            cout<<"\n";
        }else if(a == 5){
            cout<<dq.size()<<'\n';
        }else if(a == 6){
            
            cout<<dq.empty()<<'\n';
        }else if(a == 7){
            
            if(dq.empty()) cout<<-1;
            else{
                cout<<dq.front();
            }
            cout<<"\n";
        }else if(a == 8){
            
            if(dq.empty()) cout<<-1;
            else{
                cout<<dq.back();
            }
            cout<<"\n";
        }
    }
}