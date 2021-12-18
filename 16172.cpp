#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S,K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>S>>K;
    string a;
    for(int i = 0;i<S.size();i++){
        if(!(S[i]>='0'&&S[i]<='9')){
            a.push_back(S[i]);
        }
    }
    int s = a.size();
    int k = K.size();
    int fail[200005] = {0};
    for(int i = 1,j = 0;i<k;i++){
        while(j>0&&K[i]!=K[j]) j = fail[j-1];
        if(K[i]==K[j]) fail[i] = ++j;
    }
    int begin = 0,matched = 0;
    if(s < k){
        cout<<0;
        return 0;
    }
    while(begin<=s-k){
        if(matched < k&&a[begin+matched]==K[matched]){
            matched++;
            if(matched==k){
                cout<<1;
                return 0;
            }
        }else{
            if(matched==0) begin++;
            else{
                begin += matched-fail[matched-1];
                matched = fail[matched-1];
            }

        }
    }
    cout<<0;
}