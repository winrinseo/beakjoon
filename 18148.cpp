#include <iostream>

using namespace std;

int T, N, M;
string f[20];
int m;
int solve(int cur , int sel , string ff , int f_cnt){
    if(m <= sel) return 20;
    if(f_cnt == N){
        m = min(m , sel);
        return sel;
    }
    if(cur == M){
        return 20;
    }
    
    string next;
    int next_cnt = 0;

    for(int i = 0;i<N;i++){
        if(ff[i] == '0' && f[cur][i] == '0'){
            next.push_back('0');
        }else{
            next.push_back('1');
            next_cnt++;
        }
    }

    int ret = min(solve(cur + 1 , sel + 1 , next ,next_cnt) , solve(cur + 1 , sel , ff , f_cnt));

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        cin>>N>>M;

        for(int i = 0; i<M;i++){
            cin>>f[i];
        }

        m = 20;

        int ret = solve(0,0,string(N , '0') , 0);

        if(ret == 20) cout<<-1<<"\n";
        else cout<<ret<<"\n";
    }

}