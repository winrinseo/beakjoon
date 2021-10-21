#include <iostream>
#include <vector>
using namespace std;
int T,N;
bool board[305][305];
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                char a; cin>>a;
                if(a=='1') board[i][j] = true;
                else board[i][j] = false;
            }
        }
        //컴포넌트 추출이 완료된 정점
        bool finished[305]= {0};
        vector<int> scc[305];
        int sccNum[305];
        int SN = 0;
        bool sccadj[305][305] = {0};
        for(int i = 1;i<=N;i++){
            if(finished[i]) continue;
            finished[i] = true;
            scc[SN].push_back(i);
            sccNum[i] = SN;
            for(int j = 1;j<=N;j++){
                if(finished[j]) continue;
                //양쪽에서 도달 가능하다면 같은 컴포넌트.
                //i번 정점과 같은 컴포넌트
                if(board[i][j]&&board[j][i]){
                    finished[j] = true;
                    scc[SN].push_back(j);
                    sccNum[j] = SN;
                }
            }
            SN++;
        }
        int answer = 0;
        vector<pair<int,int>> ans;
        for(int i = 0;i<SN;i++){
            //컴포넌트 내의 정점이 1개이면 출력 x
            if(scc[i].size()==1) continue;
            for(int j = 1;j<=scc[i].size();j++){
                answer++;
                ans.push_back({scc[i][j-1],scc[i][j%scc[i].size()]});
            }
        }
        
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=N;j++){
                if(i==j||!board[i][j]||sccNum[i]==sccNum[j]) continue;
                    sccadj[sccNum[i]][sccNum[j]] = true;
            }
        }
        //불필요한 간선 정리
        for(int k = 0;k<SN;k++){
            for(int n =0;n<SN;n++){
                for(int m =0;m<SN;m++){
                    if(sccadj[n][m]&&sccadj[n][k]&&sccadj[k][m])
                        sccadj[n][m] = false;
                }
            }
        }
        for(int i = 0;i<SN;i++){
            for(int j = 0;j<SN;j++){
                if(sccadj[i][j]){
                    answer++;
                    ans.push_back({scc[i][0],scc[j][0]});
                }
            }
        }
        cout<<answer<<"\n";
        for(auto a : ans){
            cout<<a.first<<" "<<a.second<<'\n';
        }

    }
}