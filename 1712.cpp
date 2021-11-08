#include <iostream>
using namespace std;
int A,B,C;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>C;
    int profit = C-B;
    if(profit <= 0){
        cout<<-1;
        return 0;
    }
    int answer = A/(profit)+1;
    cout<<answer;
}