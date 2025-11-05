#include <iostream>
#include <string>
using namespace std;
string str;
int N,M;
int dp[10005][105];
int solve(int cur, int turn){
    if(cur > M){
        if(N < stoi(str))
            return 1;
        return -1;
    }

    int num = stoi(str);
    int & ret = dp[num][cur]; 

    if(ret != (1<<30))
        return ret;

    ret = turn < 0 ? 2 : -2;

    for(int i = 0;i<str.size();i++){
        char temp = str[i];
        if(str[i] == '9') str[i] = '0';
        else str[i]++;
        
        if(turn == 1) ret = max(ret , solve(cur + 1 , -turn));
        else if(turn == -1) ret = min(ret , solve(cur + 1 , -turn));
        str[i] = temp;
    }

    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>str>>M;

    N = stoi(str);

    for(int i = 0;i<10005;i++)
        for(int j = 0;j<105;j++)
            dp[i][j] = 1<<30;

    int ret = solve(1,1);
    if(ret == 1) cout<<"koosaga";
    else cout<<"cubelover";
}