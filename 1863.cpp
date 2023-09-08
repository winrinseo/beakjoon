#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    int answer = 0;
    for(int i = 0;i<N;i++){
        int aa,a; cin>>aa>>a;
        
        if(s.empty()){
            if(a != 0) s.push(a);
        }else{

            if(s.top() < a){
                s.push(a);
            }else if(s.top() > a){
                //건물을 발견했다고 봄
                while(!s.empty() && s.top() > a){
                    answer++;
                    s.pop();
                }
                //같은 건물이므로 생략한다.
                if(!s.empty() && s.top() == a) continue;
                if(a != 0) s.push(a);
            }
            
        }
    }
    //현재 스택에 남아있는 수만큼 더해줌
    answer += s.size();
    cout<<answer;
}