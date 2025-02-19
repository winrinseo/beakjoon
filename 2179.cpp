#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int N;

vector<pair<string, int>> v;
unordered_map<string,vector<pair<string,int>>> m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>N;

    for(int i = 0;i<N;i++){
        string a;
        cin>>a;
        v.push_back({a,i});
    }
    sort(v.begin() , v.end());
    int maxL = 0;
    for(int i = 0;i<N-1;i++){
        
        int L = min(v[i].first.size() , v[i+1].first.size());

        string c;
        for(int j = 0;j<L; j++){
            if(v[i].first[j] != v[i+1].first[j])
                break;
            c.push_back(v[i].first[j]);
        }

        
        maxL = max(maxL , (int)c.size());

        if(c.size() != 0){
            m[c].push_back(v[i]);
            m[c].push_back(v[i + 1]);
        }
    }
    int s = 20005;
    auto ans = m.begin();
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->first.size() == maxL){
            sort(it->second.begin(),it->second.end(),[](pair<string,int>& a , pair<string,int>& b){
                return a.second < b.second;
            });
            
            if(s > it->second[0].second){
                ans = it;
                s = it->second[0].second;
            }
        }
    }
    int cnt = 0;
    for(int i = 0;i<ans->second.size();i++){
        if(cnt == 2) break;
        if(i != 0 && ans->second[i].second == ans->second[i-1].second)
            continue;
        cout<<ans->second[i].first<<"\n";
        cnt++;
    }
}