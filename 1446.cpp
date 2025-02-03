#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct dd{
    int s,e,d;
};

int N,D;
vector<dd> v;

int d[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>D;

    for(int i = 0;i<N;i++){
        int a,b,c; cin>>a>>b>>c;
        v.push_back({a,b,c});
    }

    for(int i = 0;i<=D;i++){
        d[i] = i;
    }

    sort(v.begin() , v.end() ,[](dd & a , dd & b){
        return a.e < b.e;
    });

    for(int i = 0;i<=D;i++){
        for(int j = 0 ; j<N;j++)
            if(i == v[j].e)
                d[i] = min(d[i] , d[v[j].s] + v[j].d);
        if(i >= 1) d[i] = min(d[i] , d[i - 1] + 1);
    }

    
    cout<<d[D];
}