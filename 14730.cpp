#include <iostream>

using namespace std;


int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    int answer = 0;

    for(int i = 0; i<N;i++){
        int a,b;cin>>a>>b;

        answer += (a * b);
    }

    cout<<answer;
}