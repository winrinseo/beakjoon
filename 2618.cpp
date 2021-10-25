#include <iostream>
#include <algorithm>
#define INF 987654321
#define MAX 1005
using namespace std;
int N,W;
//d[1번 경찰차가 마지막으로 해결한 사건][2];
int d[MAX][MAX];
pair<int,int> cases[MAX];
//위치 정보와 마지막으로 해결한 사건
int dp(int oneY,int oneX,int twoY,int twoX,int one,int two){
    int next = max(one,two)+1;
    if(next > W) return 0;
    int& ret = d[one][two];
    if(ret!=INF) return ret;
    //1번 경찰차가 움직일 경우
    int dist = abs(cases[next].first-oneY)+abs(cases[next].second-oneX);
    ret = min(ret,
        dp(cases[next].first,cases[next].second,twoY,twoX,next,two)+dist);
    //2번
    dist = abs(cases[next].first-twoY)+abs(cases[next].second-twoX);
    ret = min(ret,
        dp(oneY,oneX,cases[next].first,cases[next].second,one,next)+dist);
    return ret;
}
void track(int oneY,int oneX,int twoY,int twoX,int one,int two){
    int next = max(one,two)+1;
    if(next > W) return;
    int dist1 = abs(cases[next].first-oneY)+abs(cases[next].second-oneX);
    int dist2 = abs(cases[next].first-twoY)+abs(cases[next].second-twoX);
    if(d[next][two]+dist1<d[one][next]+dist2){
        cout<<"1"<<"\n";
        track(cases[next].first,cases[next].second,twoY,twoX,next,two);
        return;
    }else{
        cout<<"2"<<"\n";
        track(oneY,oneX,cases[next].first,cases[next].second,one,next);
        return;
    }
    return;
}
int main(){
    cin>>N>>W;
    for(int i = 1;i<=W;i++){
        cin>>cases[i].first;
        cin>>cases[i].second;
    }
    for(int i = 0;i<MAX;i++)
        for(int j = 0;j<MAX;j++)
            d[i][j] = INF;
    cout<<dp(1,1,N,N,0,0)<<'\n';
    track(1,1,N,N,0,0);
}