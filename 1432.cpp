#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;


int N;
int p[55];
int outdegree[55];
vector<int> adj[55];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    priority_queue<int> q;
    for(int i = 1;i<=N;i++){
        string a;cin>>a;
        for(int j = 0;j<N;j++){
            if(a[j] == '1'){
                outdegree[i]++;
                adj[j+1].push_back(i);
            }
        }
    }
    
    for(int i = 1;i<=N;i++){
        if(outdegree[i] == 0)
            q.push(i);
    }
    int order = N;
    if(q.empty()){
        cout<<-1;
        return 0;
    }

    while(!q.empty()){
        int cur = q.top(); q.pop();
        p[cur] = order--;
        
        for(int & next : adj[cur]){
            if(--outdegree[next] == 0)
                q.push(next);
        }
        if(order > 0 && q.empty()){
            cout<<-1;
            return 0;
        }
    }

    for(int i = 1;i<=N;i++)
        cout<<p[i]<<" ";
}