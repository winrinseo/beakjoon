#include <iostream>
using namespace std;

int N;

long long dp[100005];
int arr[100005];
bool check[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    //경우의 수 미리 계산
    dp[1] = 1;
    //길이가 하나 추가될 때마다 i - 1 길이의 경우의 수를 두번 더한 다음 겹쳐지는 길이 만큼의 경우의 수를 빼서 계산
    for(int i = 2;i<=N;i++){
        dp[i] = dp[i - 1] * 2 - dp[i - 2] + 1;
    }

    for(int i = 0;i<N;i++)
        cin>>arr[i];

    //앞선 경우의 수 계산 방법을 응용해서 겹치는 만큼의 경우의 수를 제외해가며 계산
    //계산 완료된 idx;
    int idx = -1;

    int lo = 0, hi = 0;

    long long answer = 0;

    while(hi < N){
        if(!check[arr[hi]]){
            check[arr[hi]] = true;
            //부분 수열의 길이
            int cnt = hi - lo + 1;
            //겹치는 길이
            int dup = idx - lo + 1;

            answer += (dp[cnt] - dp[dup]);
            idx = hi;
            hi++;
        }else{
            check[arr[lo]] = false;
            lo++;
        }

        
    }

    cout<<answer;

}