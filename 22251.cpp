#include <iostream>

using namespace std;

int N,K,P,X;
int digit[10] = {
    0b1110111,
    0b0100100,
    0b1011101,
    0b1101101,
    0b0101110,
    0b1101011,
    0b1111011,
    0b0100101,
    0b1111111,
    0b1101111,
};

// 0b1110111,
// 0b1101011
int x[6];
int reve[10][10];

//해당 숫자로 가기 위해 LED를 반전해야하는 수 계산
int revDist(int i , int j){
    int ret = 0;
    int bit = digit[i] ^ digit[j];

    while(bit){
        if(bit & 1)
            ret++;
        bit>>=1;
    }

    return ret;
}

int solve(int cur , int cnt , int depth){
    if(depth == K){
        if(X == cur) return 0;
        if(N >= cur && cur >= 1){
            return 1;
        }
        return 0;
    }

    int ret = 0;

    for(int i = 0;i<=9;i++){

        //반전 횟수가 남아 있을때
        if(cnt + reve[x[depth]][i] <= P){
            ret += solve(cur*10+i , cnt + reve[x[depth]][i] , depth + 1);
        }
    }

    return ret;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K>>P>>X;

    for(int i = 0;i<=9;i++){
        for(int j = 0;j<= 9;j++){
            reve[i][j] = revDist(i,j);
        }
    }
    int temp = X;

    for(int i = K-1; i>=0; i--){
        x[i] = temp % 10;
        temp/=10;
    }

    cout<<solve(0,0,0);
}