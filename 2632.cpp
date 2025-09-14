#include <iostream>
#include <unordered_map>
using namespace std;

int W;
int M,N;
int prefix[2][2005];
unordered_map<int,int> cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>W;
    cin>>M>>N;
    for(int i = 1;i<=M;i++){
        cin>>prefix[0][i];
        prefix[0][i + M] = prefix[0][i];
    }
    for(int i = 1;i<=N;i++){
        cin>>prefix[1][i];
        prefix[1][i + N] = prefix[1][i];
    }

    for(int i = 1;i<=M*2;i++){
        prefix[0][i] += prefix[0][i-1];
    }

    for(int i = 1;i<=N*2;i++){
        prefix[1][i] += prefix[1][i-1];
    }

    int answer = 0;
    cnt[0] = 1;
    for(int k = 0;k<M;k++){
        for(int i = 1;i<=M;i++){
            int scale = prefix[0][i + k] - prefix[0][i - 1];
            cnt[scale]++;
            if(k == M - 1) break;
        }
    }


    for(int k = 0;k<N;k++){
        for(int i = 1;i<=N;i++){
            int scale = prefix[1][i + k] - prefix[1][i - 1];
            answer += cnt[W - scale];
            if(k == N - 1) break;
        }
    }

    cout<<answer + cnt[W];
       
}