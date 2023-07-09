#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
int N;
int m[55][55];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i<55;i++)
        for(int j = 0;j<55;j++){
            m[i][j] = 1000;
            if(i == j) m[i][j] = 0;
        }
    cin>>N;

    while(1){
        int a,b;cin>>a>>b;

        if(a == -1 && b == -1) break;

        m[a][b] = 1;
        m[b][a] = 1;
    }

    for(int k = 1;k<=N;k++){
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=N;j++){
                if(i == j) continue;
                m[i][j] = min(m[i][j] , m[i][k] + m[k][j]);
            }
        }
    }
    int ans[55];
    int sc = 1000;
    for(int i = 1;i<=N;i++){
        int s = 0;
        for(int j = 1;j<=N;j++){
            s = max(s , m[i][j]);
        }
        ans[i] = s;
        sc = min(sc,s);
    }
    
    int a = 0;
    for(int i = 1;i<=N;i++){
        if(ans[i] == sc) 
            a++;
    }
    cout<<sc<<" "<<a<<"\n";
    for(int i = 1;i<=N;i++){
        if(ans[i] == sc) 
            cout<<i<<" ";
    }
}