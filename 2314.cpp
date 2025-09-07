#include <iostream>
#include <queue>

#define MAX (1<<16)-1
#define INF 987654321
using namespace std;

int dist[MAX];
int st,ed;

int change_bit(int s ,int pos ,int dir){
    if(dir == 0){//위
        if(pos / 4 == 3) return -1;
        int p = s & 1<<pos ? 1 : 0;
        int other = s & 1<<(pos + 4) ? 1 : 0;
        if(p == other) return -1;
        s ^= 1<<(pos);
        s ^= 1<<(pos+4);
    }else if(dir == 1){//아래
        if(pos / 4 == 0) return -1;
        int p = s & 1<<pos ? 1 : 0;
        int other = s & 1<<(pos - 4) ? 1 : 0;
        if(p == other) return -1;
        s ^= 1<<(pos);
        s ^= 1<<(pos-4);
    }else if(dir == 2){//왼
        if((pos+1) % 4 == 0) return -1;
        int p = s & 1<<pos ? 1 : 0;
        int other = s & 1<<(pos + 1) ? 1 : 0;
        if(p == other) return -1;
        s ^= 1<<(pos);
        s ^= 1<<(pos+1);
    }else if(dir == 3){//오
        if(pos % 4 == 0) return -1;
        int p = s & 1<<pos ? 1 : 0;
        int other = s & 1<<(pos - 1) ? 1 : 0;
        if(p == other) return -1;
        s ^= 1<<(pos);
        s ^= 1<<(pos-1);
    }
    return s;
}

int bfs(){
    queue<int> q;

    q.push(st);

    dist[st] = 0;

    while(!q.empty()){
        int cur = q.front();q.pop();
        
        if(cur == ed) return dist[cur];
        for(int i = 0;i<16;i++){
            for(int j = 0;j<4;j++){
                int next = change_bit(cur,i,j);
                if(next == -1) continue;
                if(dist[next] != INF) continue;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    return INF;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0;i<MAX;i++){
        dist[i] = INF;
    }

    for(int i = 0;i<4;i++){
        string a;cin>>a;
        for(int j = 0;j<4;j++){
            st<<=1;
            st |= (a[j] == 'L' ? 1 : 0);
        }  
    }

    for(int i = 0;i<4;i++){
        string a;cin>>a;
        for(int j = 0;j<4;j++){
            ed<<=1;
            ed |= (a[j] == 'L' ? 1 : 0);
        }
    }

    cout<<bfs();
}