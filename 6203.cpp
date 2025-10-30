#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#define pii pair<int,int>
using namespace std;

int N;
vector<pii> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    int remain = N;
    for(int i = 0; remain > 1;i = (i + 1) % N){
        if(v[i].first == 300000) continue;
        int idx = -1;
        long long dist = INT64_MAX;
        
        for(int j = 0;j<N;j++){
            if(i == j) continue;
            if(v[j].first == 300000) continue;
            long long d = (v[i].first - v[j].first) * (v[i].first - v[j].first) 
                + (v[i].second - v[j].second) * (v[i].second - v[j].second);

            if(dist > d){
                idx = j;
                dist = d;
            }
        }

        if(idx != -1) {
            remain--;
            v[idx].first = 300000;
        }
    }

    for(int i = 0;i<N;i++){

        if(v[i].first != 300000){
            cout<<i+1;
            return 0;
        }
    }
}