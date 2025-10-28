#include <iostream>
#include <queue>
using namespace std;

int K,N;
queue<long long> arr;

long long gcd(long long a , long long b){

    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>K>>N;

    for(int i = 0;i<N;i++){
        int a;
        cin>>a;
        arr.push(a);
    }

    
    while(arr.size() > 1){
        long long a = arr.front();arr.pop();
        long long b = arr.front();arr.pop();

        arr.push(a*b/gcd(a,b));
    }

    cout<<arr.front() - K;
    
}