#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define pii pair<long long ,int>
#define ll long long

using namespace std;

int T,N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    
    while(T--){
        cin>>N;

        vector<ll> v;
        priority_queue<pii> pq;
        for(int i = 0;i<N;i++){
            ll a;cin>>a;
            v.push_back(a);
            pq.push({a,i});
        }

        ll ans = 0;

        for(int i = 0;i<N;){
            pii t = pq.top();
            if(t.second < i) {
                pq.pop();
                continue;
            }

            if(t.second >= i){
                ans += t.first - v[i];
                i++;
            }
        }
        
        cout<<ans<<'\n';

    }

}