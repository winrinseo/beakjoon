#include <iostream>

using namespace std;


int N,K;
int v[200005] , cnt[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;


    for(int i = 0;i<N;i++){
        cin>>v[i];
    }
    
    int l = 0, r = 0;
    int ans = 0;
    while(r < N){
        if(cnt[v[r]] == K){
            cnt[v[l]]--;
            l++;
        }else{
            ans = max(ans , r - l + 1);
            cnt[v[r]]++;
            r++;
        }
        
    }
    cout<<ans;
}