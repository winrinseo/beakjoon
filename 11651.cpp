#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
pii p[100005];
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>p[i].second>>p[i].first;
    }
    sort(p,p+N);
    for(int i = 0;i<N;i++){
        cout<<p[i].second<<" "<<p[i].first<<"\n";
    }
}