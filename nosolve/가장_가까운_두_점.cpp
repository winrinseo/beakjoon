#include <iostream>
#include <algorithm>
#define INF 987654321
#define pii pair<int,int>
using namespace std;
int N;
pii p[100005];
int dist(int a,int b){
    int w = abs(p[a].first - p[b].first);
    int h = abs(p[a].second - p[b].second);
    return (w*w) + (h*h);
}
int solve(int st,int ed){
    if(ed - st <= 0) return INF;
    if(ed - st == 1) return dist(st,ed);
    int mid = (st+ed)/2;
    int left = solve(st,mid-1);
    int right = solve(mid+1,ed);

    int ret = min(left,right);
    //가장 가까운 두 점이 mid점과 한쌍인 경우
    int l = mid-1 , r = mid+1;
    while(st<=l || r<=ed){
        if(st <= l) ret = min(ret,dist(l--,mid));
        if(r <= ed) ret = min(ret,dist(r++,mid));
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>p[i].first>>p[i].second;

    sort(p,p+N);
    cout<<solve(0,N-1);
}