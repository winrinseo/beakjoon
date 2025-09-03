#include <iostream>

using namespace std;

int N;
bool d[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        int a;cin>>a;

        d[a] = true;
    }


    for(int i = 9;i>=2;i--){
        if(d[i]){
            cout<<"YES"<<"\n";
            cout<<i*10+i;
            return 0;
        }
    }
    if(d[1]){
        cout<<"YES"<<"\n";
        cout<<1;
        return 0;
    }
    if(d[0]){
        cout<<"YES"<<"\n";
        cout<<0;
        return 0;
    }
    cout<<"NO";
}