#include <iostream>
#include <stack>

using namespace std;
int N;
int p[100005],a[2] = {1,1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>p[i];

    int s = 1;
    for(int i = 1;i<N;i++){
        if(p[i-1]<=p[i]) s++;
        else s = 1;
        a[0] = max(a[0],s);
    }
    s = 1;
    for(int i = 1;i<N;i++){
        if(p[i-1]>=p[i]) s++;
        else s = 1;
        a[1] = max(a[1],s);
    }
    cout<<max(a[0],a[1]);
}