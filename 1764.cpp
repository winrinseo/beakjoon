#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
unordered_set<string> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0;i<N;i++){
        string a;cin>>a;
        s.insert(a);
    }
    vector<string> an;

    for(int i = 0;i<M;i++){
        string a;cin>>a;
        if(s.count(a))
            an.push_back(a);
    }
    sort(an.begin(),an.end());
    cout<<an.size()<<"\n";
    for(auto& a : an)
        cout<<a<<"\n";
    
}