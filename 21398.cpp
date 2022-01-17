#include <iostream>
#include <algorithm>
#include <string.h>
#define INF 987654321
using namespace std;
int T;
string game;
int alice[26];
int albert[26];
int dp[2][155][155];
int solve(int l,int r,int a,int b,int turn){
    if(l > r){
        if(a<=b) return INF;
        return a-b;
    }
    int idx = turn < 0 ? 0 : 1;
    int &ret = dp[idx][l][r];
    if(ret!=-1) return ret;
    ret = turn < 0 ? INF : 0;
    int lidx = game[l]-'A', ridx = game[r]-'A';
    if(turn > 0){
        if(albert[lidx]==2&&albert[ridx]==2)
            ret = max(ret,solve(l+1,r,a+albert[lidx],b,-turn));
        else if(albert[lidx]==0&&albert[ridx]==0)
            ret = max(ret,solve(l,r-1,a,b,-turn));
        else if(albert[lidx]!=albert[ridx]){
            if(albert[lidx]==2)
                ret = max(ret,solve(l+1,r,a+albert[lidx],b,-turn));
            else ret = max(ret,solve(l,r-1,a+albert[ridx],b,-turn));
        }
    }else{
        ret = min(ret,solve(l,r-1,a,b+alice[ridx],-turn));
        ret = min(ret,solve(l+1,r,a,b+alice[lidx],-turn));
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    alice['a'-'a'] = 1,alice['l'-'a'] = 1,
    alice['i'-'a'] = 1,alice['c'-'a'] = 1,alice['e'-'a'] = 1;
    albert['a'-'a'] = 2,albert['l'-'a'] = 2,albert['b'-'a'] = 2,
    albert['e'-'a'] = 2,albert['r'-'a'] = 2,albert['t'-'a'] = 2;
    cin>>T;
    while(T--){
        for(int i =0;i<2;i++)
            for(int j = 0;j<155;j++)
                for(int z = 0;z<155;z++)
                    dp[i][j][z] = -1;
        cin>>game;
        int answer = solve(0,game.size()-1,0,0,1);
        if(answer == INF) answer = -1;
        cout<<answer<<"\n";
    }
}