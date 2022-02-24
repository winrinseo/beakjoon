#include <iostream>

using namespace std;
int C,N;
int c[35],b[10];
bool dp[40005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>C;
    for(int i = 0;i<C;i++)
        cin>>c[i];

    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>b[i];
    
    dp[0] = true;
    //추를 써서 만들 수 있는 무게
    for(int k = 0;k<C;k++){
        for(int i = 40000;i>=c[k];i--){
            if(dp[i-c[k]]){
                dp[i] = true;
            }
        }
    }
    //추를 반대로 옮겨서 만들 수 있는 무게
    //가능한 무게에서 해당 추 무게를 뺌
    for(int k = 0;k<C;k++){
        for(int i = 0;i<=40000-c[k];i++){
            if(dp[i+c[k]]){
                dp[i] = true;
            }
        }
    }
    for(int i = 0;i<N;i++){
        if(dp[b[i]]) cout<<"Y"<<" ";
        else cout<<"N"<<" ";
    }
        
}