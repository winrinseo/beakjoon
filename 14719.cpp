#include <iostream>
#include <stack>
using namespace std;

int H,M;

stack<pair<int,int>> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>H>>M;

    int hi = 0;
    int ans = 0;
    for(int i = 0;i<M;i++){
        int a;
        cin>>a;
        int cl = 1;
        while(1){
            if(s.empty()){
                hi = a;
                s.push({a , cl});
                break;
            }

            if(s.top().first <= a){
                int h = min(hi , a);
                
                ans += s.top().second * (h - s.top().first);
                cl += s.top().second;

                s.pop();

            }else{
                s.push({a , cl});
                break;
            }

        }
    }
    cout<<ans;
}