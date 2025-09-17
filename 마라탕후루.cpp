#include <iostream>

using namespace std;

int N,P,Q;
int A[105],B[105];
int ans[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>P>>Q;

    for(int i = 0;i<N;i++)
        cin>>A[i];
    for(int i = 0;i<N;i++)
        cin>>B[i];
    int cnt = 0;
    for(int i = 0;i<N;i++){
        if(cnt > 10000) break;
        while(cnt <= 10000 && A[i] != B[i]){
            A[i] += P;
            B[i] += Q;
            ans[i]++;
            cnt++;
        }
    }

    if(cnt > 10000)
        cout<<"NO";
    else{
        cout<<"YES"<<"\n";
        for(int i = 0;i<N;i++)
            cout<<ans[i]<<" ";
    }
}