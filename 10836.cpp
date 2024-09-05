#include <iostream>

using namespace std;

int N,M;
int board[705][705];
int sum[1405];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>M>>N;
    //숫자를 비교하는 순서와 범위가 작은쪽에서 큰쪽이기때문에 갱신될일없어서 그냥 다 더해줘도 됨
    for(int i = 0;i<N;i++){
        int cover = 0;
        for(int cnt = 0;cnt<3;cnt++){
            int d; cin>>d;
            sum[cover] += cnt;
            cover += d;
            sum[cover] -= cnt;
        }
    }

    for(int i = 1; i<1405;i++)
        sum[i] += sum[i-1];
    
    int cnt = 0;
    for(int i = M-1;i>=0; i--){
        board[i][0] = sum[cnt++];
    }
    
    for(int i = 1;i<M; i++){
        board[0][i] = sum[cnt++];
    }

    for(int i = 1;i<M;i++){
        for(int j = 1;j<M;j++){
            board[i][j] = max(board[i-1][j] , max(board[i][j-1] , board[i-1][j-1]));
        }
    }
    for(int i = 0;i<M;i++){
        for(int j = 0;j<M;j++){
            cout<<board[i][j]+1 <<" ";
        }
        cout<<"\n";
    }
    

}