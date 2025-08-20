#include <iostream>

using namespace std;


int N,M,K;

int sit[1005][5005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>K;

    for(int i = 0;i<N;i++){
        string a;cin>>a;
        for(int j = 0;j<M;j++){
            sit[i][j] = a[j] - '0';

        }
    }

    int answer = 0;

    for(int i = 0;i<N;i++){
        int s = 0;
        int j = 0;
        for(;j<K;j++)
            s += sit[i][j];
        
        if(s == 0) answer++;

        for(;j<M;j++){
            s += sit[i][j];
            s -= sit[i][j-K];
            
            if(s == 0) answer++;
        }
    }

    cout<<answer;
}