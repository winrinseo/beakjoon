#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int N;
double p[2005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        string a;cin>>a;
        cin>>p[i];
        p[i + N] = p[i] + 360;
    }
    sort(p , p + N + N);
    double per_minute = 5;
    double answer = 987654321;
    for(int i = N - 1;i<2*N;i++){
        double rot = p[i] - p[i-N+1];
        double m = rot / per_minute;
        m *= 60;
        answer = min(answer , m);
    }
    cout<<ceil(answer);
}