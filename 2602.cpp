#include <iostream>
#include <vector>
using namespace std;
string route;
string a;
string b;
// i번 위치에 j번째로 밟을 때의 경우의 수
int dp[105][25][2];

//문자 등장 위치
// vector<int> idx[26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    route.push_back(' ');
    a.push_back(' ');
    b.push_back(' ');
    
    string temp;
    cin>>temp;
    route += temp;
    cin>>temp;
    a += temp;
    cin>>temp;
    b += temp;


    //문자 등장 위치 기록
    // for(int i = 0;i<route.size();i++)
    //     idx[route[i] - 'A'].push_back(i);

    int N = a.size();

    //처음 밟는 위치의 값 설정
    for(int i = 1;i<=N;i++){
        if(route[1] == a[i])
            dp[i][1][0] = 1;
        if(route[1] == b[i])
            dp[i][1][1] = 1;
    }

    for(int i = 1;i<=N;i++){
        //a 루트
        //j번째로 i번 타일을 밟을 경우의 수
        for(int j = 1;j<=route.size();j++){
            if(route[j] != a[i]) continue;
            for(int k = 0; k<=i-1;k++){
                //이전 경로를 순회하며 이전에 밟았던 타일의 경우의 수를 합친다.
                dp[i][j][0] += dp[k][j-1][1];
            }
        }
        //b루트
        for(int j = 1;j<=route.size();j++){
            if(route[j] != b[i]) continue;

            for(int k = 0; k<=i-1;k++){
                dp[i][j][1] += dp[k][j-1][0];
            }
        }
    }

    int answer = 0;
    int M = route.size();
    for(int i = 1;i<=N;i++){
        answer += dp[i][M-1][0];
        answer += dp[i][M-1][1];
    }
    cout<<answer;
}