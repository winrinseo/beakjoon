#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
int N,B;
pii arr[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>B;

    for(int i = 0;i<N;i++){
        int a,b;cin>>a>>b;
        arr[i] = {a,b};
    }
    int answer = 0;
    //쿠폰을 적용할 선물
    for(int i = 0;i<N;i++){

        vector<int> v(N);

        for(int j = 0;j<N;j++){
            if(i == j){
                v[j] = (arr[j].first / 2) + arr[j].second;
            }else{
                v[j] = arr[j].first + arr[j].second;
            }
        }
        sort(v.begin() , v.end());
        int sum = B;
        int cnt = 0;
        for(int j = 0;j<N;j++){
            sum -= v[j];
            if(sum >= 0){
                cnt++;
            }else break;
        }

        answer = max(answer , cnt);
    }
    cout<<answer;
}