#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> s;
void solve(){
    if(s.size()==M){
        for(int ss : s)
            cout<<ss<<" ";
        cout<<"\n";
        return;
    }
    for(int i = 1;i<=N;i++){
        s.push_back(i);
        solve();
        s.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    solve();
}