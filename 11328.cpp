#include <iostream>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    while(N--){
        int a[26] = {0};
        int b[26] = {0};
        string aa,bb;cin>>aa>>bb;

        if(aa.size()!=bb.size()){
            cout<<"Impossible"<<"\n";
            continue;
        }
        for(int i = 0;i<aa.size();i++)
            a[aa[i]-'a']++;

        
        for(int i = 0;i<bb.size();i++)
            b[bb[i]-'a']++;

        bool flag = true;
        for(int i = 0;i<26;i++){
            if(a[i]!=b[i]){
                flag = false;
                cout<<"Impossible"<<"\n";
                break;
            }
        }
        if(flag) cout<<"Possible"<<"\n";
    }
}