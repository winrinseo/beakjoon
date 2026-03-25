#include <iostream>

using namespace std;

int N,M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>N>>M;


    int answer = N * M;
    if(N % 2 == 1 && M % 2 == 1) answer-=1;
    cout<<answer;
}