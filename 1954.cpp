#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int N;
pii p[105];
int M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++)
        cin>>p[i].first>>p[i].second;


    sort(p , p + N);

    cin>>M;
    int G = 1;
    while(true){
        int m = M;
        int i = 0;
        for(;i<N;i++){
            int ax = G - p[i].second;
            if(ax <= 0) break;
            if(ax % p[i].first == 0){
                m -= (ax / p[i].first);
            }else break;
        }
        if(m < 0){
            cout<<0;
            break;
        }
        if(m == 0 && i == N){
            cout<<G;
            break;
        }
        G++;
    }
}