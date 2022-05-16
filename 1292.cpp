#include <iostream>
using namespace std;
int a,b;
int s[55];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1;i<55;i++)
        s[i] = s[i-1]+i;
    cin>>a>>b;
    int answer = 0;
    int i = 1;
    for(;s[i] < a; i++) {}
    if(b<=s[i]){
        answer += (i)*(b-a+1);
    }else{
        answer += (i)*(s[i]-a+1);
        i++;
        for(;s[i] < b; i++) 
            answer+= i*(s[i]-s[i-1]);
        
        answer+= (i)*(b-s[i-1]);
    }
    cout<<answer;
}