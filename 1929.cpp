#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> prime;
void isPrime(){
    bool check[1000005]={0};
    for(int i = 2;i<=1000000;i++){
        if(!check[i]){
            prime.push_back(i);
            for(int j = i+i;j<=1000000;j+=i){
                check[j] = true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    isPrime();
    cin>>N>>M;
    for(int i = 0;i<prime.size();i++){
        if(prime[i]>=N&&prime[i]<=M)
            cout<<prime[i]<<"\n";
    }
}