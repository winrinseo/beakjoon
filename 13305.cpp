#include <iostream>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
int N;
int dist[100005];
ll prefix[100005];
pii city[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N-1;i++)
        cin>>dist[i];

    for(int i = 0;i<N;i++){
        cin>>city[i].first;
        city[i].second = i;
    }

    for(int i = N-2;i>=0;i--)
        prefix[i] = prefix[i+1]+dist[i];
    
    sort(city,city+N);

    int p = N-1;
    ll answer = 0;

    for(int i = 0;i<N;i++){
        if(p > city[i].second){
            ll total = prefix[city[i].second] - prefix[p];
            answer += total*city[i].first;
            p = city[i].second;
        }
    }

    cout<<answer;
    
}