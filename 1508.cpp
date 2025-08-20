#include <iostream>
#include <vector>
using namespace std;

int N,M,K;
int point[55];
bool answer[55];

bool solve(int d){

    //첫 심판을 세웠다고 가정
    for(int i = 0; i < K; i++){
        int m = M - 1;
        int cur = point[i];

        vector<bool> temp(K);
        temp[i] = true;

        // 다음 심판
        for(int j = i + 1; j < K;j++){
            if(m == 0) break;
            if(point[j] - cur  >= d){
                m--;
                cur = point[j];
                temp[j] = true;
            }
        }

        if(m == 0){
            for(int i = 0;i<K;i++){
                answer[i] = temp[i];
            }
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>K;

    for(int i = 0;i<K;i++){
        cin>>point[i];
    }


    int lo = 1, hi = 1000000;

    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(solve(mid)){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    for(int i = 0;i<K;i++)
        cout<<answer[i];
}