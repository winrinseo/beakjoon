#include <iostream>
using namespace std;
int N;
bool adj[105][105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin>>adj[i][j];
        }
    }
    for(int k = 0;k < N;k++){
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(adj[i][k]&&adj[k][j])
                    adj[i][j] = true;
            }
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
}