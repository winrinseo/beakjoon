#include <iostream>

using namespace std;
int N;
int d[4] = {3,2,0,2};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int answer = 0;

    for(int i = 2023;i<=N;i++){
        if(N < i) break;
        int a = 0;
        int t = i;
        while(t){
            if((t%10) == d[a]){
                a++;
            }
            t/=10;
            if(a == 4) break;
        }
        if(a == 4) answer++;
    }
    cout<<answer;
}