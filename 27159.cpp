#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[35];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>p[i];
    
    sort(p,p+N);

    int ans = p[0];

    for(int i = 1;i<N;i++){
        if(p[i] - p[i-1] != 1)
            ans += p[i];
    }

    cout<<ans;
}