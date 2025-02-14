#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

struct cmp{
    bool operator()(pair<int,int> & a , pair<int,int> & b){
        return a.first > b.first;
    }
};

int N,M;
int dist[105] , go[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<N+M;i++){
        int a,b;cin>>a>>b;
        go[a] = b;
    }

    for(int i = 0;i<=100;i++){
        dist[i] = INF;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>> , cmp> pq;


    pq.push({0,1});

    dist[1] = 0;

    while(!pq.empty()){
        pair<int,int> cur = pq.top();pq.pop();

        // 사다리나 뱀이 있을 때
        if(go[cur.second]){
            if(dist[go[cur.second]] > cur.first){
                dist[go[cur.second]] = cur.first;
                pq.push({cur.first , go[cur.second]});
            }
        }else{

            for(int i = 1;i<=6;i++){
                int next = cur.second + i;

                if(next > 100) continue;
                if(dist[next] > cur.first + 1){
                    dist[next] = cur.first + 1;
                    pq.push({cur.first + 1 , next});
                }
            }
        }
    }

    cout<<dist[100];

}