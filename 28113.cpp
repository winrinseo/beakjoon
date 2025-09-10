#include <iostream>

using namespace std;

int N,A,B;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>A>>B;

    if(A < B) cout<<"Bus";
    else if(A == B) cout<<"Anything";
    else cout<<"Subway";
}