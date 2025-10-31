#include <iostream>

using namespace std;

int N,L,C;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>L>>C;
    int answer = 987654321;
    C++;
    for(int i = 1;i<=N;i++){
        if(i % 13 == 0) continue;
        int a = i * L + i;
        if(a <= C){
            int s = N / i;
            int remain = N % i;
            if(remain != 0) {
                s++;
                if(remain % 13 == 0) {
                    int move = (C - (remain * L + remain)) / (L+1);
                    if(move <= 1 && (i - 1) % 13 == 0)
                        s++;
                }
            }
            answer = min(answer , s);
        }
    }
    cout<<answer;

}