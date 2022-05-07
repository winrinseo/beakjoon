#include <iostream>
using namespace std;
int T,N;
int p[40005],L[40005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N;
        int len = 0;
        for(int i = 1;i<=N;i++)
            cin>>p[i];
        for(int i = 1;i<=N;i++){
            int* pos = lower_bound(L+1,L+len+1,p[i]);
            *pos = p[i];
            if(pos==L+len+1)
                len++;
        }
        cout<<len<<"\n";
    }
}