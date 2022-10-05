#include <iostream>

using namespace std;
int N,M;
string a,b;
int idx,aidx;
bool check[26];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>a>>M>>b;
    idx = a.size()-1;
    aidx = 0;
    int ans = 0;
    for(char& s : a){
        check[s-'a'] = true;
    }
    while(aidx != b.size()){
        if(!check[b[aidx]-'a']){
            cout<<-1;
            return 0;
        }
        idx++;
        ans++;
        idx%=a.size();
        if(a[idx] == b[aidx]) aidx++;
        if(aidx == b.size()) break;
        
    }
    cout<<ans;
}