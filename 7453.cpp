#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll res = 0;
vector<ll> h;
vector<pair<ll,ll>> _h;
int N;
//a,b,c,d
ll arr[4][4005];
int idx = -1;
bool find(ll target){
    if(_h.empty()) return false;
    int lo=0,hi=_h.size();
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(_h[mid].first==target){
            idx = mid;
            return true;
        }   
        else if(_h[mid].first > target){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    return false;
}
//재귀의 깊이를 절반씩 나누어 진행
//a,b
void left(int cur,ll sum){
    if(cur>1){
        h.push_back(sum);
        return;
    }
    for(int i = 0;i<N;i++){
        left(cur+1,sum+arr[cur][i]);
    }
}
void right(int cur,ll sum){
    if(cur>3){
        if(find(0-sum)){
            res+=_h[idx].second;
        }
        return;
    }
    for(int i = 0;i<N;i++){
        right(cur+1,sum+arr[cur][i]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>arr[0][i];
        cin>>arr[1][i];
        cin>>arr[2][i];
        cin>>arr[3][i];
    }
    left(0,0);
    sort(h.begin(),h.end());
    for(int i = 0; i<h.size();i++){
        if(_h.empty()){
            _h.push_back({h[i],1});
        }else if(h[i]==_h.back().first)
            _h.back().second++;
        else _h.push_back({h[i],1});
    }
    right(2,0);
    cout<<res;
}