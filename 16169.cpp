#include <iostream>
#include <queue>

using namespace std;

int N;
int t[105];
priority_queue<int> get_time[105];
vector<int> degree[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++){
        int a,b;cin>>a>>b;

        degree[a].push_back(i);
        t[i] = b;
    }

    int answer = 0;

    for(int i = 0;i<degree[1].size();i++){
        get_time[degree[1][i]].push(0);
    }

    for(int d = 1;d<=N;d++){
        // 현재 단계에서 가장 오래 걸리는 시간
        int total_time = 0;
        for(int i = 0;i<degree[d].size();i++){
            int cur = degree[d][i];
            // 정보를 다 받은 시간
            int complete_time = get_time[cur].top();
            complete_time += t[cur];
            total_time = max(total_time , complete_time);
            // 데이터 전송
            for(int j = 0;j<degree[d+1].size();j++){
                int next = degree[d+1][j];
                get_time[degree[d+1][j]].push(complete_time + (cur - next) * (cur - next));
            }
        }

        if(degree[d+1].empty()) {
            cout<<total_time;
            return 0;
        }
    }
    return 0;
}