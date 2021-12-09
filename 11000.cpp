#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int N;
struct cmp{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        //if(a.second == b.second) 
        return a.first > b.first;
        //return a.second > b.second;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    cin>>N;
    for(int i = 0;i<N;i++){
        int a,b;cin>>a>>b;
        pq.push({a,b});
    }
    multiset<int> a;
    while(!pq.empty()){
        if(a.empty()){
            a.insert(-pq.top().second);
        }else{
            set<int>::iterator it = a.lower_bound(-pq.top().first);
            if(it==a.end()){
                a.insert(-pq.top().second);
            }else{
                a.erase(it);
                a.insert(-pq.top().second);
            }
        }
        pq.pop();
    }
    cout<<a.size();
}