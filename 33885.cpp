#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;
int N,M;
bool time_table[5][30];
int score[15];

vector<pii> lec_time[15];

int solve(int cur){
    if(cur == N) return 0;

    int ret = solve(cur + 1);

    int flag = true;
    for(int i = 0;i<lec_time[cur].size();i++){
        if(time_table[lec_time[cur][i].first][lec_time[cur][i].second]){
            flag = false;
            break;
        }
    }


    if(flag){
        for(int i = 0;i<lec_time[cur].size();i++)
            time_table[lec_time[cur][i].first][lec_time[cur][i].second] = true;

        ret = max(ret , solve(cur + 1) + score[cur]);

        for(int i = 0;i<lec_time[cur].size();i++)
            time_table[lec_time[cur][i].first][lec_time[cur][i].second] = false;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<N;i++){
        int s,k;cin>>s>>k;
        score[i] = s;
        for(int j = 0;j<k;j++){
            string str;cin>>str;
            int t;cin>>t;
            if(str == "MON"){
                lec_time[i].push_back({0,t});
            }else if(str == "TUE"){
                lec_time[i].push_back({1,t});
            }else if(str == "WED"){
                lec_time[i].push_back({2,t});
            }else if(str == "THU"){
                lec_time[i].push_back({3,t});
            }else if(str == "FRI"){
                lec_time[i].push_back({4,t});
            }
        }
    }

    if(solve(0) >= M)
        cout<<"YES";
    else
        cout<<"NO";

}