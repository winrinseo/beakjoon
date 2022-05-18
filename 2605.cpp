#include <iostream>
#include <list>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    list<int> a;
    cin>>N;
    for(int i = 1;i<=N;i++){
        auto it = a.end();
        int b;cin>>b;
        for(int j = 0;j<b;j++) it--;
        a.insert(it,i);
    }
    for(auto i = a.begin();i!=a.end();i++)
        cout<<*i<<" ";
}