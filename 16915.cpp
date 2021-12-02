#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
int N,M;
vector<int> adj[200500];
//방의 상태
bool door[100005];
//idx번 방과 연결된 스위치 번호
vector<int> sw[100005];

int dfsn[200500],sccn[200500];
bool finished[200500];
stack<int> s;
int num , sn = 1;

int getScc(int curr){
    dfsn[curr] = ++num;
    s.push(curr);
    int res = dfsn[curr];

    for(int next : adj[curr]){
        if(dfsn[next]==0)
            res = min(res,getScc(next));
        else if(!finished[next])
            res = min(res,dfsn[next]);
    }

    if(res == dfsn[curr]){
        while(1){
            int t = s.top(); s.pop();
            sccn[t] = sn;
            finished[t] = true;
            if(t==curr) break;
        }
        sn++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 1;i<=N;i++)
        cin>>door[i];
    
    for(int i = 1;i<=M;i++){
        int a; cin>>a;
        for(int j = 0;j < a;j++){
            int b; cin>>b;
            //b번 문에 i번 스위치를 연결
            sw[b].push_back(i);
        }
    }
    
    for(int i = 1;i<=N;i++){
        /*i번 문이 닫혀있는 경우 스위치 하나를 
        누르고 다른하나를 누르지않는 절 두개를 추출*/
        //열려있다면 스위치를 두개 다 누르거나 누르지 않아야함
        int a = sw[i][0], b = sw[i][1];
        if(door[i]){
            //a와 b 둘 다 누르거나 누르지않으면 참이됨 (a XNOR b)
            //(a|~b)and(~a|b)
            //열린경우 a가 눌리면 b도 눌려야함
            adj[a*2+1].push_back(b*2+1);
            adj[b*2].push_back(a*2);

            adj[a*2].push_back(b*2);
            adj[b*2+1].push_back(a*2+1);
        }else{
            //a와 b 둘중 하나만 눌려야 참이됨 (a XOR b)
            //(a|b)and(~a|~b)
            //닫힌 경우 a가 눌리면 b는 눌리면 안됨
            adj[a*2+1].push_back(b*2);
            adj[b*2+1].push_back(a*2);

            adj[a*2].push_back(b*2+1);
            adj[b*2].push_back(a*2+1);
        }
    }

    for(int i = 1;i<=M*2+1;i++){
        if(dfsn[i]==0) getScc(i);
    }
    for(int i = 1;i<=M;i++){
        if(sccn[i*2]==sccn[i*2+1]){
            cout<<0;
            return 0;
        }
    }
    cout<<1;
}