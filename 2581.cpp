#include <iostream>
#include <cmath>
using namespace std;
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int answer[2]={0,987654321};
    for(int k = n;k<=m;k++){
        if(k==1) continue;
        bool flag = true;

        for(int i = 2;i<=sqrt(k);i++){
            if(k%i==0){
                flag = false;
                break;
            }
        }
        if(flag){
            answer[0]+=k;
            answer[1] = min(answer[1],k);
        } 
    }
    if(answer[0]==0) cout<<-1;
    else cout<<answer[0]<<"\n"<<answer[1];
}