#include <iostream>

using namespace std;

long long X,Y,W,S;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>X>>Y>>W>>S;

    if(X<Y) swap(X,Y);

    long long answer = min(Y * 2 * W , Y * S);

    long long remain = 0;
    if((X-Y) % 2 == 1){
        remain = min((X - Y) * W , (X - Y - 1) * S + W);
    }else{
        remain = min((X - Y) * W , (X - Y) * S);
    }
    answer += remain;
    cout<<answer;
}