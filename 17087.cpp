#include <iostream>
#include <queue>
using namespace std;

int N,S;
priority_queue<int> sister;

int gcd(int a , int b){
    if(a < b) swap(a,b);

    while(b!=0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>S;

    for(int i = 0;i<N;i++){
        int a;cin>>a;

        sister.push(abs(S-a));
    }

    int answer = sister.top();

    while(!sister.empty()){
        answer = gcd(answer,sister.top());
        sister.pop();
    }

    cout<<answer;
}