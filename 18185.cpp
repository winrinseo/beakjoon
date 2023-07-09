#include <iostream>
#include <stack>
using namespace std;
int N;
int p[10005];
stack<int> s,ds;
int cost[4] = {0,3,5,7};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        cin>>p[i];
    }

    for(int i = N-1;i>=0;i--){
        ds.push(p[i]);
    }
    int ans = 0;
    while(!ds.empty()){
        if(ds.top() == 0) {
            ds.pop();
            continue;
        }
        int minv = 987654321;
        while(!ds.empty()){
            if(ds.top() == 0 || s.size() == 3) break;
            if(s.size() == 2 && s.top() > ds.top()) {
                minv = min(minv,(s.top() - ds.top()));
                break;
            }
            minv = min(minv,ds.top());
            s.push(ds.top());
            ds.pop();
        }
        ans += minv * cost[s.size()];
        while(!s.empty()){
            ds.push(s.top()-minv);
            s.pop();
        }
    }
    cout<<ans;
}