#include <iostream>

using namespace std;
int N;
int p[100005];
int L;
bool solve(int k){
    int res = 0;
    for(int i = 0;i<N;i++){
        res += min(p[i],k);
        if( res > L ) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int m = 0;
    for(int i = 0;i<N;i++){
        cin>>p[i];
        m = max(m,p[i]);
    }
    cin>>L;

    int lo = 1 , hi = m;
    int answer = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;

        if(solve(mid)){
            lo = mid + 1;
            answer = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout<<answer;
}