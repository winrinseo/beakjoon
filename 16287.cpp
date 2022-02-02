#include <iostream>
#include <algorithm>
using namespace std;
int W,N;
int p[200005];
bool dp[800000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>W>>N;
    for(int i = 0;i<N;i++) cin>>p[i];
    sort(p,p+N);
    //모든 원소의 값이 다른 것을 이용해
    //a+b+c+d = w 를 a+b = w-(c+d)로 바꿔서 2중 for문으로 해결
    for(int i = 0;i<N;i++){
        for(int j = i+1;j<N;j++){
            if(p[i]+p[j]>=W) continue;
            if(dp[W - (p[i]+p[j])]){
                cout<<"YES";
                return 0;
            }
        }

        for(int j = 0;j < i;j++){
            dp[p[i]+p[j]] = true;
        }
    }
    cout<<"NO";
    return 0;
}