#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
using namespace std;
int N;
pii p[200005];
priority_queue<int,vector<int>,greater<int>> pq; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>p[i].first>>p[i].second;
    

    sort(p,p+N,[](pii& a,pii& b){
        if(a.first==b.first)
            return a.second > b.second;
        return a.first < b.first;
    });
    int t = 0;
    int answer = 0;
    for(int i = 0;i<N;i++){
        if(pq.empty()||t < p[i].first){
            answer+=p[i].second;
            pq.push(p[i].second);
            t++;
        }else if(pq.top()<p[i].second){
            answer-=pq.top(); pq.pop();
            answer+=p[i].second; pq.push(p[i].second);
        }
    }
    cout<<answer;
}