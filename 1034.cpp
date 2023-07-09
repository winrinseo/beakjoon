#include <iostream>
#define ll long long
using namespace std;

int N,M,K;
ll p[55];
bool check[55];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 0 ;i < N;i++){
        for(int j = 0; j < M;j++){
            char a;cin>>a;
           if(a == '1') p[i] |= 1LL << j;
        }
    }
    cin>>K;
    int answer =0;
    for(int i = 0;i<N;i++){
        //이미 계산을 마친 행이면 생략
        if(check[i]) continue;

        check[i] = true;
        int cnt = 1;
        for(int j = i + 1;j<N;j++){
            if(p[i] == p[j]){
                cnt++;
                check[j] = true;
            }
        }

        //0의 개수를 센다
        int zero = 0;
        for(int x = 0;x<M;x++){
            if( !(p[i] & (1LL<<x)))
                zero++;
        }

        //램프를 전부 켜기 위한 조건만큼 횟수에서 제외
        int k = K - zero;
        if(k < 0) continue;
        //남은 수가 짝수면 유효함
        if(k % 2 == 0){
            answer = max(answer , cnt);
        }
    }

    cout<<answer;

}