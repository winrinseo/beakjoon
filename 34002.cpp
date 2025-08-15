#include <iostream>
using namespace std;

int A,B,C;

int S,V;

int L;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>A>>B>>C;
    cin>>S>>V;

    cin>>L;

    //필요 경험치
    int remain = (250 - L) * 100;

    int s = 0 , v = 0;

    int answer = 0;
    while(remain > 0){
        if(v){
            remain -= C;
            v--;
            answer++;
            continue;
        }else if(s){
            remain -= B;
            s--;
            answer++;
            continue;
        }

        if(V){
            v = 30;
            V--;
            continue;
        }

        if(S){
            s = 30;
            S--;
            continue;
        }

        remain -= A;
        answer++;

    }

    cout<<answer;
    
    
}