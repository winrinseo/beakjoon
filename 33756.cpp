#include <iostream>
#include <unordered_map>

using namespace std;

long long T,N;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;


    while(T--){
        cin>>N;

        if(N % 8){
            cout<<"No"<<'\n';
            continue;
        }

        long long cnt_eight = N / 8;
        long long cnt = 0;

        long long m = 111111111111111111;

        while(m){
            cnt += cnt_eight / m;
            cnt_eight %= m;
            m/=10;
        }

        if(cnt > 8){
            cout<<"No"<<'\n';
        }else cout<<"Yes"<<'\n';
    }

}