#include <iostream>
#include <algorithm>
using namespace std;
int N , A , B;
int p[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>N>>A>>B;

    for(int i = 0; i<=N;i++){
        cin>>p[i];
    }

    sort(p + 1, p + N + 1);

    int sum = p[0];

    int answer = sum / A;

    for(int i = 1; i <= N;i++){
        sum += p[N - i + 1] ;
        answer = max(answer , sum / (A + (B * i)));

    }

    cout<<answer;

}