#include <iostream>
using namespace std;

int N,K,A,B;
int p[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K>>A>>B;

    int size = N / A;
    for(int i =0;i<size;i++)
        p[i] = K;
    

    int answer = 1;
    int turn = 0;
    while(1){
        //A는 N의 약수기 때문에 A크기의 블록으로 관리

        p[turn] += B;
        turn = (turn + 1) % size;

        for(int i = 0;i<size;i++){
            if(--p[i] == 0){
                cout<<answer;
                return 0;
            }
        }
        answer++;
    }
}