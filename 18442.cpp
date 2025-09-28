#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll V,P,L;

vector<ll> vil;
ll ans_dist = 1000000000000000;
vector<ll> answer;

void solve(int last , int cnt, vector<ll>& sel){
    if(cnt == P){
        ll sum = 0;

        for(int i = 0;i<vil.size();i++){
            ll min_dist = 1000000000000000;

            for(int j = 0;j<sel.size();j++){
                min_dist = min({min_dist , abs(vil[i] - sel[j]) , L - abs(vil[i] - sel[j])});
            }
            sum += min_dist;
        }

        if(ans_dist > sum){
            ans_dist = sum;
            answer.clear();
            for(int i = 0;i<sel.size();i++){
                answer.push_back(sel[i]);
            }
        }
        return;
    }

    for(int i = last + 1; i<vil.size();i++){
        sel.push_back(vil[i]);
        solve(i , cnt+1,sel);
        sel.pop_back();
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>V>>P>>L;

    for(int i = 0;i<V;i++){
        ll a;cin>>a;
        vil.push_back(a);
    }
    vector<ll> sel;
    solve(-1 , 0 , sel);

    cout<<ans_dist<<"\n";
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}