#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

int N;
vector<pii> p;

int dist(pii a, pii b){
    return (a.first - b.first) * (a.first - b.first) + 
        (a.second - b.second) * (a.second - b.second);
}

int solve(int st , int ed){
    if(ed - st == 1)
        return dist(p[st] , p[ed]);
    if(ed - st == 2)
        return min({dist(p[st] , p[st + 1]) , dist(p[st] , p[ed]),dist(p[st + 1] , p[ed])});

    int mid = (st + ed)/2;
    int ret = min(solve(st , mid) , solve(mid + 1 , ed));
    
    vector<pii> v;
    int line = (p[mid].first + p[mid].first) / 2;

    for(int i = st;i<=ed;i++){
        if((line - p[i].first) * (line - p[i].first) < ret)
            v.push_back(p[i]);
    }

    sort(v.begin() , v.end(),[](pii & a , pii & b){
        return a.second < b.second;
    });

    for(int i = 0;i<v.size();i++){
        for(int j = i + 1;j<v.size();j++){
            if((v[j].second - v[i].second) * (v[j].second - v[i].second) >= ret)
                break;
                ret = min(ret , dist(v[i] , v[j]));
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        int a,b;cin>>a>>b;

        p.push_back({a,b});
    }
    sort(p.begin() , p.end(),[](pii & a , pii & b){
        return a.first < b.first;
    });

    cout<<solve(0,p.size()-1);
}