#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//file종류,개수
int dp[2005][2];
bool isfol[2005];
vector<int> adj[2005];
bool visited[2005];
unordered_map<string,int> num;
int N,M,Q;
void dfs(int cur){
    dp[cur][0] = 0;
    dp[cur][1] = 0;
    visited[cur] = 1;
    for(int& next : adj[cur]){
        if(!isfol[next]){
            if(!visited[next])
                dp[cur][0]++;
            dp[cur][1]++;
        }
        dfs(next);
        dp[cur][0] += dp[next][0];
        dp[cur][1] += dp[next][1];
    }
}
vector<string> split(string s){
    string a;
    vector<string> ret;
    for(int i = 0;i<s.size();i++){
        if(s[i]=='/'){
            ret.push_back(a);
            a.clear();
        }else{
            a.push_back(s[i]);
        }
    }
    if(!a.empty()) ret.push_back(a);
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    num["main"] = 0;
    int cnt = 1;
    int T = N+M;
    while(T--){
        string a,b;bool c;
        cin>>a>>b>>c;
        if(!num.count(a)) num[a] = cnt++;
        if(!num.count(b)) num[b] = cnt++;
        adj[num[a]].push_back(num[b]);
        isfol[num[b]] = c;
    }
    cin>>Q;
    for(int i = 0;i<Q;i++){
        string s; 
        cin>>s;
        vector<string> aa = split(s);
        fill(visited,visited+2005,0);
        int folnum = num[aa.back()];
        dfs(folnum);
        cout<<dp[folnum][0]<<" "<<dp[folnum][1]<<"\n";
    }
}