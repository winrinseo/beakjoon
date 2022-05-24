#include <iostream>
#include <algorithm>
#define psi pair<string,int>
using namespace std;
int N,M;
psi a[100005];
string b[100005];
int bs(string t){
    int l = 0,r = N-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid].first==t)
            return a[mid].second;
        else if(a[mid].first > t){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 1;i<=N;i++){
        string p;cin>>p;
        b[i] = p;
        a[i-1] = {p,i};
    }
    sort(a,a+N);

    for(int i = 0;i<M;i++){
        string p;cin>>p;
        if('0' <= p[0]&&p[0]<='9'){
            cout<<b[stoi(p)]<<"\n";
        }else{
            cout<<bs(p)<<"\n";
        }
    }
    
}