#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using ll = long long;
int N,H;
vector<tuple<ll,ll,ll>> room;
bool solve(ll hp){
    ll curH = hp;
    ll atk = H;

    for(int i =0;i<N;i++){
        ll type = get<0>(room[i]);
        ll a = get<1>(room[i]);
        ll h = get<2>(room[i]);
        if(type==1){
            int times = h / atk;
            if(h%atk > 0) times++;
            //용사가 먼저 공격하기 때문에 사망시점 몬스터보다 한대 덜맞음
            curH -= (a*(times-1));
            if(curH <= 0) return false;
        }else{
            atk+=a;
            curH+=h;
            if(curH>hp) curH = hp;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>H;
    for(int i = 0;i<N;i++){
        ll a,b,c; cin>>a>>b>>c;
        room.push_back({a,b,c});
    }
    ll lo = 1, hi = (INT64_MAX-1);
    ll answer = 0;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(solve(mid)){
            hi = mid-1;
            answer = mid;
        }else{
            lo = mid+1;
        }
    }
    cout<<answer;
}