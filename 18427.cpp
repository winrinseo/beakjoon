#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N,M,H;
vector<int> block[55];
int dp[1005];

vector<int> split(string p){
    vector<int> ret;

    string s;

    for(int i = 0;i<p.size();i++){
        if(p[i] != ' '){
            s.push_back(p[i]);
        }else{
            ret.push_back(stoi(s));
            s.clear();
        }
    }

    if(!s.empty()) 
        ret.push_back(stoi(s));

    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>H;
    string line;
    getline(cin,line);

    for(int i = 0;i<N;i++){
        getline(cin,line);
        block[i] = split(line);
    }

    dp[0] = 1;
    for(int i = 0;i<N;i++){
        for(int k = H;k>=1;k--){
            for(int j = 0;j<block[i].size();j++){
                if(k - block[i][j] < 0) continue;
                dp[k] %= 10007;
                dp[k] += dp[k - block[i][j]];
                dp[k] %= 10007;
            }
        }
    }

    cout<<dp[H] % 10007;
    
}
