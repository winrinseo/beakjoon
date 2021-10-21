#include <iostream>
#include <vector>
#include <set>
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
            }
        }
        //컴포넌트 추출이 완료된 정점
        bool finished[305]= {0};
        int SN = 0;
        for(int i = 1;i<=N;i++){
            if(finished[i]) continue;
            finished[i] = true;
            for(int j = 1;j<=N;j++){
                //양쪽에서 도달 가능하다면 같은 컴포넌트.
                //i번 정점과 같은 컴포넌트
                if(board[i][j]&&board[j][i]){
                    
                }
            }
        }
        

    }
}