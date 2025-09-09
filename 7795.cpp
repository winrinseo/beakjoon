#include <iostream>
#include <queue>
using namespace std;

int T,N,M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>T;

    while(T--){
        priority_queue<int> A;
        priority_queue<int> B;

        int a,b;cin>>a>>b;

        for(int i = 0;i<a;i++){
            int n;cin>>n;
            A.push(n);
        }

        for(int i = 0;i<b;i++){
            int n;cin>>n;
            B.push(n);
        }
        int ans = 0;
        while(!A.empty()){
            int cur = A.top(); A.pop();

            while(!B.empty() && B.top() >= cur) B.pop();
            ans += B.size();

            if(B.empty()) break;
        }
        cout<<ans<<"\n";
    }

}