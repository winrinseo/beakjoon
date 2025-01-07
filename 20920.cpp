#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int N,M;
unordered_map<string,int> m;
vector<pair<string,int>> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<N;i++){
        string a; cin>>a;

        if(a.size() < M) continue;

        m[a]++;
    }

    v = vector<pair<string,int>>(m.begin() , m.end());

    sort(v.begin() , v.end() , [](pair<string,int> & a , pair<string , int> & b){
        if(a.second == b.second){
            if(a.first.size() == b.first.size()){
                return a.first < b.first;
            }
            return a.first.size() > b.first.size();
        }
        return a.second > b.second;
    });

    for(int i = 0;i<v.size();i++){
        cout<<v[i].first<<"\n";
    }
    
}