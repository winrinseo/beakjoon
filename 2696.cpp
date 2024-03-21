#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T,M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    
    while(T--){

        cin>>M;

        cout<<M/2+1<<"\n";
        int cnt = 0;
        priority_queue<long long> a , b;

        for(int i = 1;i<=M;i++){
            long long s;cin>>s;
            if(a.size() == b.size()){
                a.push(s);
            }else{
                b.push(-s);
            }
            if(!b.empty() && a.top() > -b.top()){
                long long aa = a.top(); a.pop();
                long long bb = -b.top(); b.pop();
                a.push(bb);
                b.push(-aa);
            }

            if( i % 2 == 1){
                cnt++;
                cout<<a.top()<<" ";
                if(cnt % 10 == 0)
                    cout<<"\n";
            }
        }
        cout<<"\n";
    }
    
}