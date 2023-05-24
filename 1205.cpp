#include <iostream>
#include <algorithm>
using namespace std;

int N,S,P;
int p[55];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>S>>P;
    for(int i = 0;i<N;i++)
        cin>>p[i];
    p[N] = S;
    sort(p,p+N+1,[](int & a,int & b) {return a > b;});

    int overlap = 0;
    int rank = 0;
    int me = 0;
    for(int i = 0;i<=N;i++){
        if(i > 0 && p[i-1] == p[i]){
            overlap++;
        }else if(!me){
            rank++;
            rank+=overlap;
            overlap = 0;
        }
        if(S == p[i]){
            me++;
        }
    }
    // cout<<rank<<" "<<me<<"\n";
    if(rank + me - 1 <= P)
        cout<<rank;
    else
        cout<<-1;
}