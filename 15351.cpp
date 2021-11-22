#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin.ignore();
    for(int i = 0;i < N;i++){
        string a;
        getline(cin,a);
        int ret = 0;
        for(int j = 0;j<a.size();j++){
            if(a[j]!=' '){
                ret+=(a[j]-'A')+1;
            }
        }
        if(ret==100) cout<<"PERFECT LIFE"<<"\n";
        else cout<<ret<<"\n";
    }
}