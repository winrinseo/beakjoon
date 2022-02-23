#include <iostream>

using namespace std;
int N;
int p[105];
bool visited[105];
int answer = 0;
//dfs시 시작지점으로 돌아오지 못하면 쌍이 될 수 없다
bool dfs(int cur,int st,int cnt){
    visited[cur] = true;
    bool ret = false;
    
    if(!visited[p[cur]]){
        ret = dfs(p[cur],st,cnt+1);
    }else if(p[cur]==st){
        answer+=cnt;
        return true;
    }else false;

    if(!ret) visited[cur] = false;
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for(int i = 1;i<=N;i++)
        cin>>p[i];

    for(int i = 1;i<=N;i++){
        if(!visited[i])
            dfs(i,i,1);
    }
    cout<<answer<<"\n";
    for(int i = 1;i<=N;i++)
        if(visited[i])
            cout<<i<<"\n";
}