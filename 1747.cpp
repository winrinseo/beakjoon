#include <iostream>
#include <vector>
using namespace std;

bool isPrime[2000001];
vector<int> pprime;

bool isPel(int n){
    int temp = n;
    int comp = 0;
    while(temp){
        comp *= 10;
        comp += temp%10;
        temp /= 10;
    }
    return n == comp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0;i<=2000000;i++){
        isPrime[i] = true;
    }

    
    for(int i = 2;i<=2000000;i++){
        if(!isPrime[i])
            continue;

        for(int j = i * 2; j<=2000000;j += i)
            isPrime[j] = false;
    }

    for(int i = 2;i<=2000000;i++){
        if(isPrime[i] && isPel(i))
            pprime.push_back(i);
    }

    int N;
    cin>>N;

    int idx = lower_bound(pprime.begin() , pprime.end() , N) - pprime.begin();
    cout<<pprime[idx];
}