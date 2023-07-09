#include <iostream>
using namespace std;
int p[10];
int N;
int answer = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    while(N){
        int n = N%10;
        if(p[6]<p[9] && p[9] && n == 9) p[6]++;
        else if(p[9]<p[6] && p[6] && n == 6) p[9]++;
        else p[n]++;
        N/=10;
    }
    for(int i = 0;i<10;i++) 
         answer = max(answer,p[i]);
    cout<<answer;
}