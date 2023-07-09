#include <iostream>
#include <cmath>
using namespace std;

int N,M;
int board[20][20];

int solve(int y , int x){
    int ret = -1;
    for(int i = 0;i<4;i++){

        for(int i = 0;i<N;i++){
            for(int j = 0 ;j<M;j++){
                int xx = j , yy = i;
                int r = 0;
                while(( xx >= 0 && xx < M) && (yy >= 0 && yy < N)){
                    r *= 10;
                    r += board[yy][xx];
                    
                    if((int)sqrt(r) * (int)sqrt(r) == r){
                        ret = max(ret , r);
                    }
                    xx += x;
                    yy += y;

                }
            }
        }
        if( i % 2 == 0) y *= -1;
        else x *= -1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            char a;cin>>a;
            board[i][j] = (a - '0');
            
        }
    }
    int answer = -1;
    for(int y = 0;y<=N;y++){
        for(int x = 0; x<=M;x++){
            if(y == 0 && x == 0) continue;
            answer = max(answer , solve(y , x));
        }
    }
    cout<<answer;
}