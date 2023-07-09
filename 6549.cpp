#include <iostream>
#define ll long long
using namespace std;
int N;
ll arr[100005];
ll solve(int st,int ed){
    if(st==ed) return arr[st];
    int mid = (st+ed)/2;
    ll left = solve(st,mid);
    ll right = solve(mid+1,ed);
    ll ret = max(left,right);

    ll h = arr[mid]; int l = mid , r = mid;
    while(st < l || r < ed){
        if((r == ed && st < l) || (r!=ed && st!=l && arr[l-1] > arr[r+1])){
            l--;
            h = min(h,arr[l]);
            ret = max(ret,h*(r-l+1));
        }

        if((l==st && r < ed) || (r!=ed && st!=l &&arr[l-1] <= arr[r+1])){
            r++;
            h = min(h,arr[r]);
            ret = max(ret,h*(r-l+1));
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>N;
        if(N==0) break;
        for(int i = 0;i<N;i++)
            cin>>arr[i];
        cout<<solve(0,N-1)<<"\n";
    }
}