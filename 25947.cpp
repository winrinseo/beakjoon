#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N,B,A;
int p[100005];
stack<int> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>B>>A;


    for(int i = 0;i<N;i++){
        cin>>p[i];
    }
    sort(p , p + N);

    int m = 0;
    int answer = 0;
    for(int i = 0;i<N;i++){
        if(m + p[i] <= B){
            m += p[i];
            s.push(p[i]);
            answer++;
        }else {
            if(!A) continue;
            A--;
            int dis = p[i] / 2;
            while(A && !s.empty() && m + dis > B){
                A--;
                m -= s.top() / 2;
                s.pop();
            }
            if(m + dis <= B){
                m += dis;
                answer++;
            } 
        }
    }
    cout<<answer;
}