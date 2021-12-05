#include <iostream>
#include <algorithm>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int x[100005] = {0};
    int y[100005] = {0};
    for(int i = 0;i<N;i++){
        cin>>x[i]>>y[i];
    }
    sort(x,x+N);
    sort(y,y+N);
    cout<<(x[N-1]-x[0])*(y[N-1]-y[0]);
}