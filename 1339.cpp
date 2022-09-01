#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#define pii pair<int,int>
using namespace std;

int N;
int cnt = 9;
pii cost[26];
string s[15];
int n[26];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    for(int i = 0;i<N;i++){
        cin>>s[i];
        for(int j = 0;j<s[i].size();j++){
            cost[s[i][j]-'A'].first += pow(10,s[i].size()-j-1);
            cost[s[i][j]-'A'].second = (s[i][j]-'A');
        }
    }
    sort(cost,cost+26);
    for(int i = 25;i>=0;i--){
        if(cnt < 0) break;
        if(cost[i].first == 0) continue;
        n[cost[i].second] = cnt--;
    }
    int ans = 0;

    for(int k = 0;k<N;k++){
        int a = 0;
        for(int i = 0;i<s[k].size();i++){
            a *= 10;
            a += n[s[k][i] - 'A'];
        }
        ans += a;
    }
    cout<<ans;
    
}