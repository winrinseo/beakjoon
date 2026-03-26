#include <iostream>
#define LIMIT 210
using namespace std;
int K;
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>K>>N;
    K--;
    int time = 0;
    while(N--){
        int t; char c;


        cin>>t>>c;

        if(time + t >= LIMIT){
            cout<<K+1;
            return 0;
        }

        time += t;

        if(c == 'T'){
            K = (K+1) % 8;
        }
    }
}