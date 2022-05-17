#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int N;
pii p[1005];
bool visited[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>p[i].first>>p[i].second;     
    
    sort(p,p+N);
    int total = 0;
    for(int i = 0;i<N;i++){
        if(visited[i]) continue;
        total += p[i].second;
        int next = 0,idx = -1;

        for(int j = i+1;j<N;j++){
            if(p[j].second >= next){
                next = p[j].second;
                idx = j;
            }
            if(next > p[i].second) break;
        }
        
        if(p[i].second < next){
            total+=p[i].second*(p[idx].first-(p[i].first+1));
        }else{
            total+=p[idx].second*(p[idx].first-(p[i].first+1));
        }
        for(int j = i;j<idx;j++)
            visited[j] = 1;
    }
    cout<<total;
}