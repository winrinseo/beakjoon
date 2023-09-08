#include <iostream>
#include <set>
#include <string>
using namespace std;
int N, C;
char a;
set<string> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>a;
    if(a =='Y') C = 2;
    if(a =='F') C = 3;
    if(a =='O') C = 4;
    for(int i = 0;i<N;i++){
        string aa;cin>>aa;
        s.insert(aa);
    }
    cout<<((int)s.size() / (C-1));
}