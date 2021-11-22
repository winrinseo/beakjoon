#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
int N;
tuple<int,int,string> per[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        string b; cin>>b;
        per[i] = {a,i,b};
    }
    sort(per,per+N);
    for(int i = 0;i<N;i++){
        cout<<get<0>(per[i])<<" "<<get<2>(per[i])<<"\n";
    }
}