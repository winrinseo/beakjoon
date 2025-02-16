#include <iostream>
#include <vector>
#include <algorithm>

#define INF 10001
using namespace std;


int T , K;
string s;

vector<int> m[26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;

    while(T--){
        cin>>s;
        cin>>K;

        for(int i = 0;i<26;i++)
            m[i].clear();


        int lo = INF , hi = -1;

        for(int i = 0;i<s.size();i++){
            m[s[i] - 'a'].push_back(i);
        }

        for(int i = 0;i<26;i++){
            
            if(m[i].size() >= K){
                
                for(int j = 0; j + K - 1< m[i].size(); j++){
                    lo = min(lo , m[i][j + K - 1] - m[i][j] + 1);
                    hi = max(hi , m[i][j + K - 1] - m[i][j] + 1);
                }
            
            }
        }
        if(lo == INF)
            cout<<-1<<"\n";
        else cout<<lo<<" "<<hi<<"\n";
        
    }
    
}