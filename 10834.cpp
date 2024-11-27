#include <iostream>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    int dir = 0;
    int cur = 1;
    for(int i = 0;i<N;i++){
        int a,b,c;
        cin>>a>>b>>c;

        cur = (max(cur , a) / min(cur , a)) * b;
        dir = c == 0 ? dir : (dir+1) % 2;
    }

    cout<<dir<<" "<<cur;
}