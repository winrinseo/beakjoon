#include <iostream>
#include <stack>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    stack<pair<int,int>> s;
    long long answer = 0;
    for(int i = 0;i<N;i++){
        int num; cin>>num;

        if(s.empty()) {
            s.push({num,1});
        }
        else{
            while(!s.empty()&&s.top().first<num){
                answer+=s.top().second;
                s.pop(); 
            }
            if(!s.empty()) {
                if(s.top().first==num) {
                    pair<int,int> curr = s.top();
                    s.pop();
                    answer+=curr.second;
                    if(!s.empty()) answer++;
                    curr.second++;
                    s.push(curr);
                }
                else {
                    answer++;
                    s.push({num,1});
                }
            }else{
                 s.push({num,1});;
            }
            
        }
    }
    cout<<answer;
}