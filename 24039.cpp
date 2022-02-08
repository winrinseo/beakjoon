#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> prime;
bool check[20005];
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2;i<=sqrt(20000);i++){
        if(check[i]) continue;
        prime.push_back(i);
        for(int j = i*i;j<=20000;j+=i){
            check[j] = true;
        }
    }
    cin>>N;
    for(int i = 1;i<prime.size();i++){
        if(prime[i-1]*prime[i] > N){
            cout<<prime[i-1]*prime[i];
            return 0;
        }
    }    
    
}