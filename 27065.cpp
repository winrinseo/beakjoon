#include <iostream>
#include <cmath>
using namespace std;
int T,N;
bool ans[5001]; // 답
bool tb[5001]; // 과잉수인지 아닌지
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1;i<=5000;i++){
        bool rs = 1;//정답 판별
        int sum = 0;
        for(int j = 2;j<=int(sqrt(i));j++){
            if( i % j == 0 ){
                int m = i/j;
                //약수 하나라도 과잉수면 답이 안됨
                if(tb[j] == 1 || tb[m] == 1) rs = 0;
                sum += (j + m);
                if(j == m) sum -= m;
            }
        }
        if(sum + 1 > i) tb[i] = 1;
        if(rs && sum + 1 > i) ans[i] = 1;
    }
    cin>>T;

    while(T--){
        cin>>N;

        if(ans[N]) cout<<"Good Bye"<<"\n";
        else cout<<"BOJ 2022"<<"\n";
    }
    
}