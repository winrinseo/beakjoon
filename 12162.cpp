#include <iostream>
#define ll long long
using namespace std;

int T;
int B,N;
ll b[10];

ll search(ll k){
    ll ret = 0;
    // k 시간동안 b[i]가 시작할 수 있는 손님의 수
    for(int i = 0;i<B;i++){
        ret += (k / b[i]) + 1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;

    for(int t = 1;t<=T;t++){
        cin>>B>>N;
        ll m = 0;
        for(int i = 0;i<B;i++){
            cin>>b[i];
            m = max(m , b[i]);
        }
        if(B >= N){
            cout<<"Case #"<<t<<": "<<N<<"\n";
            continue;
        }
        //손님을 n명 처리할 시간
        ll times = 0;
        ll lo = 0, hi = m * N;

        while(lo <= hi){
            ll mid = (lo + hi) / 2;
            // N번째 손님이 이발을 시작한 시간
            if(search(mid) >= N){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        times = lo;
        
        int answer = 0;
        // 정확히 times에 시작한 사람의 수
        int cnt = N - search(times - 1);
        
        for(int i = 0;i<B;i++){
            //times에 시작할 수 있는 바버
            if(times % b[i] == 0){
                cnt--;
                if(cnt <= 0){
                    answer = i + 1;
                    break;
                }
            }
        }
        
        cout<<"Case #"<<t<<": "<<answer<<"\n";
    }
}