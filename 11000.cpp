#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N;
bool cmp(pair<int,int>& a,pair<int,int>& b){
    return a.second<b.second;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    vector<pair<int,int>> t;
    for(int i = 0;i<N;i++){
        int a,b;cin>>a>>b;
        t.push_back({a,b});
    }
    sort(t.begin(),t.end());
    int ret = 0;
    set<int> check;
    for(int i = 0;i<N;i++){
        if(check.lower_bound(t[i].first)!=check.end()){
            check.insert(t[i].second);
        }else if(!check.count(t[i].first)){
            ret++;
            check.insert(t[i].second);
        }
    }
    cout<<ret;
}