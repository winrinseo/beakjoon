#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct cus{
    int p,t,c;
};
int N,T,W,M;
queue<cus> q;
cus arr[200005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>T>>W;

    for(int i = 0;i<N;i++){
        int a,b;
        cin>>a>>b;
        q.push({a, b, 0});
    }
    cin>>M;

    for(int i = 0;i<M;i++){
        cin>>arr[i].p>>arr[i].t>>arr[i].c;
    }

    sort(arr , arr + M , [](cus & a , cus & b){
        return a.c < b.c;
    });

    // for(int i = 0;i<M;i++){
    //     q.push(arr[i]);    
    // }

    int t = 0;
    int m_id = 0;
    while(t < W){
        cus cur = q.front();q.pop();
        
        
        for(int i = 0;i<min(cur.t , T);i++){
            cout<<cur.p<<"\n";
            
            if(++t >= W) break;
        }
        
        for(;m_id<M;){
            if(t >= arr[m_id].c)
                q.push(arr[m_id++]);
            else break;
        }
        cur.t -= T;
        if(cur.t > 0){
            q.push(cur);
        }
    }
}