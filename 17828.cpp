#include <iostream>
#include <vector>
using namespace std;

int N,X;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>X;

    int x = X - N;
    if(x < 0 || x > (25 * N)){
        cout<<"!";
        return 0;
    }

    string str = string(N,'A');

    int y = x / 25;
    int i = N - 1;
    for(; i >= N - y;i--)
        str[i] = 'Z';
    
    str[i]+=(x%25);

    cout<<str;
}