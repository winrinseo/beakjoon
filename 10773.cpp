#include <iostream>
#include <stack>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>N;
    int sum = 0;
    stack<int> s;
    int a;
    for(int i = 0;i<N;i++){
        cin>>a;
        if(a != 0){
            sum+=a;
            s.push(a);
        }else{
            sum-=s.top(); s.pop();
        }
    }
    cout<<sum;
}