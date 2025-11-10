#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> adj[100005];

int n = -1;

int stt[100005] , edd[100005];
int seg[400005];

void ett(int cur){
    stt[cur] = ++n;
    for(int & next : adj[cur])
        ett(next);
    edd[cur] = n;
}

void update(int idx, int st, int ed, int l , int r, int diff){
    if(r < st || ed < l) return;
    if(l<= st && ed <= r){
        seg[idx] += diff;
        return;
    }
    int mid = (st + ed) / 2;
    update(idx * 2 , st , mid , l , r, diff);
    update(idx * 2 + 1, mid + 1 , ed , l , r, diff);
}

int check(int idx, int st, int ed, int l , int r){
    if(r < st || ed < l) return 0;
    if(st == ed) return seg[idx];

    int mid = (st + ed) / 2;
    return check(idx * 2 , st , mid , l , r) + check(idx * 2 + 1 , mid + 1 , ed , l , r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    
    for(int i = 1;i<=N;i++){
        int a;cin>>a;
        if(a != -1)
            adj[a].push_back(i);
    }

    ett(1);

    for(int i = 0;i<M;i++){
        int a,b,c;
        cin>>a>>b;

        if(a == 1){
            cin>>c;
            update(1,0,N-1,stt[b] , stt[b] , c);
        }else{
            cout<<check(1,0,N-1,stt[b] , edd[b])<<"\n";
        }
    }
}