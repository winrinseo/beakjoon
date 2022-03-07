#include <iostream>

using namespace std;
string s,t;
int cnt[26];
int answer = 0;
bool isvalid(int n){
    if(n>0&&cnt[n-1]<=cnt[n])
        return false;
    return true;
}
bool complete(){
    for(int i = 0;i<t.size();i++){
        if(!cnt[i]) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>t;

    for(int i = 0;i<s.size();i++){
        for(int j =0;j<t.size();j++){
            if(s[i]==t[j]){
                if(isvalid(j)){
                    cnt[j]++;
                    if(complete()){
                        answer++;
                        for(int i = 0;i<t.size();i++){
                            cnt[i]--;
                        }
                    }
                }
            }
        }
    }
    cout<<answer;
}