#include <iostream>
#define ll long long
using namespace std;

ll N,K;
ll arr[200005] , prefix[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;

    for(int i = 1;i<=N;i++){
        cin>>arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }
    ll answer = 0;
    // 실린더를 비빌 위치
    for(ll i = 1;i<=N;i++){
        // 반시계 방향으로 돌려 i위치에 도달할 수 있는 거리
        ll ccw = min(i - 1 , K);
        //시계 방향
        ll cw = min(N - i , K);

        // 돌리면서 획득한 점수 + 남은 횟수를 i위치에 비빈 점수
        ll score_ccw = prefix[ccw] + (arr[i] * (K - ccw));
        ll score_cw = prefix[N] - prefix[N-cw] + (arr[i] * (K - cw));
        ll total = max(score_ccw , score_cw);
        answer = max(answer , total);
        cout<<i<<" "<<score_ccw<<" "<<score_cw<<"\n";
    }
    cout<<answer;
}