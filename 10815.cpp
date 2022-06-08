#include <iostream>
#include <unordered_set>
using namespace std;
int N,M;
unordered_set<int> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        s.insert(a);
    }
    cin>>M;
    for(int i = 0;i<M;i++){
        int a;cin>>a;
        cout<<s.count(a)<<" ";
    }
}