#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

unordered_map<string, int> id;
unordered_map<int, string> id_to_name;

vector<vector<int>> adj;

vector<string> split(string str){
    string s;
    vector<string> ret;
    for(int i = 0;i<str.size();i++){
        if(str[i] == ' '){
            ret.push_back(s);
            s.clear();
        }else{
            s.push_back(str[i]);
        }
    }

    if(!s.empty()) ret.push_back(s);
    return ret;
}

void bfs(int cur , vector<string> & answer){
    queue<pair<int,int>> q;
    vector<bool> visited(adj.size());
    
    q.push({cur,0});
    visited[cur] = 1;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.second == 2){
            answer.push_back(id_to_name[cur.first]);
            continue;
        }

        for(int & next : adj[cur.first]){
            if(!visited[next]){
                visited[next] = 1;
                q.push({next , cur.second + 1});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    while(getline(cin,str)){
        
        // 그래프 정보 재정의
        if(str == "GRAPH BEGIN"){
            id.clear();
            id_to_name.clear();
            adj.clear();
            int num = 1;
            adj.push_back({});
            while(1){
                getline(cin,str);
                // 그래프 끝이 나올때까지 반복
                if(str == "GRAPH END")
                    break;
                
                vector<string> ret = split(str);
                // 처음 나왔다면 id 부여
                if(id.find(ret[0]) == id.end()){
                    adj.push_back({});
                    id[ret[0]] = num;
                    id_to_name[num++] = ret[0];
                }

                for(int i = 1;i<ret.size();i++){
                    if(id.find(ret[i]) == id.end()){
                        adj.push_back({});
                        id[ret[i]] = num;
                        id_to_name[num++] = ret[i];
                    }
                    adj[id[ret[0]]].push_back(id[ret[i]]);
                    adj[id[ret[i]]].push_back(id[ret[0]]);
                }
            }
        }else{
            //query
            vector<string> answer;
            bfs(id[str] , answer);
            sort(answer.begin(), answer.end());
            for(int i = 0;i<answer.size();i++){
                cout<<answer[i]<<" ";
            }
            cout<<"\n";

        }

        
    }
}