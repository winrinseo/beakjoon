#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int N;
string a[20005];
bool cmp(string& a,string& b){
    if(a.size()==b.size())
        return a < b;
    return a.size()<b.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    set<string> overlap;
    for(int i = 0;i<N;i++){
        cin>>a[i];
    }
    sort(a,a+N,cmp);
    cout<<"--------"<<"\n";
    for(int i = 0;i<N;i++){
        if(overlap.count(a[i])) continue;
        cout<<a[i]<<'\n';
        overlap.insert(a[i]);
    }
}