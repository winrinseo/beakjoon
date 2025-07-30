#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int N,L;
pii hole[10005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>L;

    for(int i = 0;i<N;i++){
        int a,b;
        cin>>a>>b;

        hole[i] = {a,b};
    }

    sort(hole , hole + N);

    int answer = 0;

    int builded = -1;

    for(int i = 0;i<N;i++){
        int start = max(builded + 1 , hole[i].first);
        int s = hole[i].second - start;
        if(s <= 0) continue;
        int m = s / L;
        if(s % L) m++;
        answer += m;

        builded = (start - 1) + m * L;
    }

    cout<<answer;

}