#include <iostream>
#include <deque>


using namespace std;

int M,K;
deque<int> dq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>K;

    for(int i = 0;i<M;i++){
        dq.push_back(i);
    }
    string cmd;
    cin>>cmd;

    for(int i = 0;i<cmd.size();i++){
        if(cmd[i] == 'A'){
            int temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }else if(cmd[i] == 'B'){
            int temp1 = dq.front();
            dq.pop_front();
            int temp2 = dq.front();
            dq.pop_front();
            dq.push_back(temp2);
            dq.push_front(temp1);
        }
    }

    for(int i = 0;i<M;i++){
        if(i == K - 1){
            for(int j = 0; j < 3;j++){
                cout<<dq.front()<<" ";
                dq.pop_front();
            }
            break;
        }
        dq.pop_front();
    }
}