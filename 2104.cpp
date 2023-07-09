#include <iostream>
#define ll long long
using namespace std;

int N;
ll p[100005];
ll solve(int st,int ed){
    if(st == ed) return p[st] * p[st];
    int mid = (st+ed)/2;

    ll ret = max(solve(st,mid),solve(mid+1,ed));

    int l = mid,r = mid;
    ll sum = p[mid] , minn = p[mid];
    ll ans = sum*sum;
    while(st < l || r < ed){
        int go;
        if(l == st && r < ed) go = ++r;
        else if(r == ed && st < l) go = --l;
        else if(p[l-1] < p[r+1]) go = ++r;
        else go = --l;
        sum+=p[go];
        minn = min(minn,p[go]);
        ans = max(ans,sum*minn);
    }
    return max(ans,ret);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>p[i];
    }

    cout<<solve(0,N-1);
}