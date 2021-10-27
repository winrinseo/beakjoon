#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    int a,b,v; cin>>a>>b>>v;
    int answer = (v-a)/(a-b)+1;
    if((double)answer != (double)(v-a)/(a-b)+1) answer++;
    cout<< answer;
}