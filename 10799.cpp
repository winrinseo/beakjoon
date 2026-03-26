#include <iostream>
#include <stack>
using namespace std;

string str;
stack<pair<char,int>> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>str;


    int answer = 0;

    for(int i = 0;i<str.size();i++){
        if(str[i] == '('){
            s.push({'(',i});
        }else{
            //레이저인 경우
            if(i - s.top().second == 1){
                s.pop();
                answer += s.size();
            }else{// 막대인 경우
                s.pop();
                answer += 1;
            }
        }
    }

    cout<<answer;
}