#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,K;
bool c[1005];
vector<int> a;
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    for(int i = 1;i<=N;i++) q.push(i);

    while(!q.empty()){

        int cnt = 0;
        while(++cnt!=K){
            q.push(q.front());q.pop();
        }
        a.push_back(q.front());
        q.pop();
    }
    cout<<"<";
    for(int i = 0;i<a.size();i++){
        cout<<a[i];
        if(i!=a.size()-1) cout<<", ";
    }
    cout<<">";
}