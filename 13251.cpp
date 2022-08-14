#include <iostream>
using namespace std;

int M,K;
int arr[50];
double answer = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    cin>>M;
    int N = 0;
    for(int i = 0;i<M;i++){
        cin>>arr[i];
        N += arr[i];
    }
    
    cin>>K;

    for(int i = 0;i<M;i++){
        double a = 1;
        for(int k = 0;k<K;k++){
            a *= (arr[i]-k)/(double)(N-k);
        }
        answer += a;
    }
    cout<<answer;
}