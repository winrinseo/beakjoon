#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int N;
vector<pii> v;
stack<int> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    int r = 1000005;
    for(int i = 0;i<N;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end());

    for(int i = 1;i<N;i++){
        if((v[i-1].second != v[i].second))
            r = min(r , abs(v[i-1].first - v[i].first) - 1);
    }

    int answer = 0;
    for(int i = 0;i<N;i++){
        if(v[i].second == 0) continue;

        if(s.empty() || v[i].first - s.top() > r){
            answer++;
        }
        s.push(v[i].first);
    }
    cout<<answer;
}