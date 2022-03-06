#include <iostream>

using namespace std;
int N;
int p[1000005],answer[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1;i <= N;i++)
        cin>>p[i];
    
    int lo = 1,hi = 2;

    while(hi<=N){
        if(p[lo]!=p[hi]){
            answer[lo] = hi;
            lo++;
        }else{
            hi++;
        }
    }
    for(int i = 1;i<=N;i++)
        if(!answer[i])
            cout<<-1<<" ";
        else cout<<answer[i]<<" ";
}