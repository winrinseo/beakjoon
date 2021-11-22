#include <iostream>
#include <set>
using namespace std;
int N,M;
bool exist[100005];
int main(){
    set<int> hash;
    cin>>N;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        hash.insert(a);
    }
    cin>>M;
    for(int i = 0;i<M;i++){
        int a; cin>>a;
        if(hash.find(a)!=hash.end())
            cout<<1<<"\n";
        else cout<<0<<"\n";
    }

}