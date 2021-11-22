#include <iostream>
using namespace std;
int N;
int main(){
    cin>>N;
    int answer = 0;
    for(int i = 1;i < N;i++){
        int a = i;
        int M = i;
        while(a){
            M+=a%10;
            a/=10;
        }
        if(M==N) {
            answer = i;
            break;
        };
    }
    cout<<answer;
}