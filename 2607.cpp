#include <iostream>

using namespace std;

int N;

string s[105];

int cnt[105][26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++) {
        cin>>s[i];
    }

    //첫 단어의 구성
    for(int i = 0;i<s[0].size();i++){
        cnt[0][s[0][i] - 'A'] ++;
    }

    int ans = 0;
    for(int i = 1;i<N;i++){

        if(abs((int)s[0].size() - (int)s[i].size()) > 1) continue;

        for(int j = 0;j<s[i].size();j++){
           cnt[i][s[i][j] - 'A']++;
        }

        int diff = 0;

        for(int j = 0;j<26;j++){
            diff += abs(cnt[0][j] - cnt[i][j]);
        }
        if(diff <= 2){ // 두 단어가 동일한 구성
            ans++;
        }
    }
    cout<<ans;
}