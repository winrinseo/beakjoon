#include <iostream>

using namespace std;
int N,L;
int p[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>L;

    for(int i = 1; i<=N;i++){
        cin>>p[i];
        p[i] += p[i-1];
    }

    int answer = 0;

    for(int i = 1;i<=N;i++){
        int a = p[i];
        if(i >= L) a -= p[i - L];

        if(129 <= a && a <= 138) answer++;
    }

    cout<<answer;
}