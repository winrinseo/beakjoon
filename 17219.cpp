#include <iostream>
#include <map>
using namespace std;
int N,M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    map<string,string> dic;
    for(int i = 0;i<N;i++){
        string a,b;
        cin>>a>>b;
        dic[a] = b;
    }
    for(int i = 0;i<M;i++){
        string a;cin>>a;
        cout<<dic[a]<<"\n";
    }
}