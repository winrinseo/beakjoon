#include <iostream>
using namespace std;
using lint = long long;
lint N,K;

lint solve(lint x){
    //x가 몇번째 수인지
    lint ret = 0;
    for(lint i = 1; i<= N; i++){
        ret += min(x / i , N);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;

    lint lo = 1 , hi = N * N;
    lint answer = 0;
    while(lo <= hi){
        lint mid = (lo + hi) / 2;
        lint ret = solve(mid);
        if(ret < K){
            lo = mid + 1;
        }else {
            answer = mid;
            hi = mid - 1;
        }
    }
    cout<<answer;
    
}