#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int T,N,num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>num;
        int sequence = 0;
        queue<pair<int,int>> q;
        priority_queue<int> value;
        for(int i = 0;i<N;i++){
            int a;cin>>a;
            q.push({i,a});
            value.push(a);
        }
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            if(curr.second==value.top()){
                ++sequence;
                if(curr.first==num){
                    cout<<sequence<<"\n";
                    break;
                }
                value.pop();
            }else if(curr.second < value.top()){
                q.push(curr);
            }
        }
    }
}