#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


int N;
unordered_map<string,int> m;
vector<pair<string,int>> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    int n = N * (N-1) / 2;

    for(int i = 0;i<n;i++){
        string a,b;int aa,bb;
        cin>>a>>b>>aa>>bb;

        if(aa > bb) {
            m[a] += 3;
            m[b] += 0;
        }
        else if(aa < bb){
            m[b] += 3;
            m[a] += 0;
        } else {
            m[a]++;
            m[b]++;
        }
    }

    for(auto it = m.begin();it != m.end();it++){
        v.push_back({it->first,it->second});
    }

    sort(v.begin(),v.end() , [](pair<string,int> & a ,  pair<string,int> & b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    });


    for(int i = 0;i<v.size();i++){
        if(i == 5) break;
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}
