#include <iostream>

using namespace std;
int d[6] = {500 , 100 , 50 , 10 , 5, 1};
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    N = 1000 - N;
    int answer = 0;

    for(int i = 0;i<6;i++){
        answer += (N / d[i]);
        N %= d[i];
    }
    cout<<answer;
}