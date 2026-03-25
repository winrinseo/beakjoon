#include <iostream>
#include <algorithm>
using namespace std;

int Y,C,P;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>Y>>C>>P;

    C/=2;

    cout<<min({Y,C,P});
}