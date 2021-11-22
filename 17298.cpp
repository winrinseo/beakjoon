#include <iostream>
#include <stack>
using namespace std;
int N;
int res[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    stack<pair<int,int>> s;
    for(int i = 0;i<1000005;i++) res[i] = -1;
    for(int i = 0;i<N;i++){
        int num;cin>>num;

        if(s.empty()){
            s.push({num,i});
        }else{
            while(!s.empty()&&s.top().first < num){
                res[s.top().second] = num;
                s.pop();
            }
            s.push({num,i});
        }
    }
    for(int i = 0;i<N;i++)
        cout<<res[i]<<" ";
}