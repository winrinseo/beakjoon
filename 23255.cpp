#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<int> adj[100005];

int num[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    for(int i = 1;i<=N;i++){

        priority_queue<int , vector<int>, greater<int>> pq;
        int g_num = 0;
        
        for(int & next : adj[i]){
           
            // 부여된 번호가 있을 경우
            if(num[next] != 0)
                pq.push(num[next]);
        }
        

        // 비어있는 가장 작은 번호 탐색
        while(!pq.empty()){
            if(pq.top() - g_num >= 2) break;
            g_num = pq.top();
            pq.pop();
            
        }
        num[i] = g_num + 1;

        cout<<num[i]<<" ";
    }

}