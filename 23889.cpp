#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

int N,M,K;
int arr[100005];
vector<pii> p;
vector<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>K;

    for(int i = 1;i<=N;i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }

    for(int i = 0;i<K;i++){
        int a;cin>>a;
        q.push_back(a);
    }
    q.push_back(N+1);

    for(int i = 0;i<q.size()-1;i++)
        p.push_back({q[i] , arr[q[i+1] - 1] - arr[q[i] - 1]});
    
    
    sort(p.begin(),p.end(),[](pii & a , pii & b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    vector<int> answer;

    for(int i = 0;i<M;i++)
        answer.push_back(p[i].first);
    
    sort(answer.begin(),answer.end());
    
    for(int i = 0;i<M;i++)
        cout<<answer[i]<<"\n";
    
}