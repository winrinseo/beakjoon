#include <iostream>
#include <algorithm>
using namespace std;

int N , K;
int p[1005][5];
int s[1005];

bool cmp(int& a, int& b){
    if(p[a][0] == p[b][0]){
        if(p[a][1] == p[b][1]){
            return p[a][2] > p[b][2];
        }
        return p[a][1] > p[b][1];
    }
    return p[a][0] > p[b][0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i = 1;i<=N;i++)
        s[i] = i;
    for(int i = 0;i<N;i++){
        int c;cin>>c;
        cin>>p[c][0]>>p[c][1]>>p[c][2];
    }
    sort(s+1,s+N+1,cmp);
    
    int ans = 0;
    p[0][0] = p[0][1] = p[0][2] = 1000005;
    int b = 0;
    for(int i = 1;i<=N;i++){
        if(s[i-1] == K) break;
        //순위 비교
        if(p[s[i-1]][0] == p[s[i]][0]){
            if(p[s[i-1]][1] == p[s[i]][1]){
                if(p[s[i-1]][2] == p[s[i]][2]){
                    b++;
                }else{
                    ans++;
                    ans+=b;
                    b = 0;
                }
            }else{
                ans++;
                ans+=b;
                b = 0;
            }
        }else{
            ans++;
            ans+=b;
            b = 0;
        }
        
    }
    cout<<ans;
}