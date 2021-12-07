#include <algorithm>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
string N; int M;
bool visited[1000005][11];
int bfs(){
    queue<pair<string,int>> q;
    q.push({N,0});
    visited[stoi(N)][0] = true;
    int ret = -1;

    while(!q.empty()){
        string curr = q.front().first;
        int hk = q.front().second; q.pop();
        if(hk==M) {
            ret = max(ret,stoi(curr));
            continue;
        }
        for(int i = 0;i<curr.size();i++){
            for(int j = i+1;j<curr.size();j++){
                if(i==0&&curr[j]=='0') continue;
                string nv = curr;
                char temp = nv[i];
                nv[i] = nv[j];
                nv[j] = temp;
                int idx = stoi(nv);
                if(visited[idx][hk+1]) continue;
                visited[idx][hk+1] = true;
                q.push({nv,hk+1});
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>N>>M;
    cout<<bfs();
}