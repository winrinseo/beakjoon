#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
int pos[1005];
stack<int> s[3];
vector<int> command;
int n = 1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        int put;cin>>put;

        // 일단 stack 1에 넣음
        s[1].push(put);
        pos[put] = 1;
        command.push_back(1);

        // 현재 찾는 수가 스택 어딘가에 있을 때
        while(pos[n] != 0){
            // 꺼내기
            int out = pos[n] == 1 ? 12 : 21;

            // 맨 위가 n이 아닐 경우
            while(s[pos[n]].top() != n){
                //다른 스택으로 옮김
                s[out%10].push(s[pos[n]].top());
                pos[s[pos[n]].top()] = out % 10;
                command.push_back(out);
                s[pos[n]].pop();
            }

            // 맨 위가 n일 때
            s[pos[n]].pop();
            command.push_back(-pos[n]);
            pos[n++] = 0;
        }
    }

    for(int i = 0;i<command.size();i++){
        cout<<command[i]<<"\n";
    }
}