#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int N;
pii p[1000005],an[1000005];
bool cmp(pii& a,pii& b){
    return a.second < b.second;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        p[i] = {a,i};
    }
    sort(p,p+N);
    an[0].first = 0; an[0].second = p[0].second;
    for(int i = 1;i<N;i++){
        if(p[i-1].first != p[i].first){
            an[i].first = an[i-1].first+1;
            an[i].second = p[i].second;
        }
            
        else {
            an[i].first = an[i-1].first;
            an[i].second = p[i].second;
        }
    }
    sort(an,an+N,cmp);
    for(int i = 0;i<N;i++)
        cout<<an[i].first<<" ";
}