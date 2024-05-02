#include <iostream>
#include <algorithm>

using namespace std;

int N,L;
int s[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>L;

    for(int i = 0;i<N;i++){
        cin>>s[i];
    }

    sort(s , s + N);

    int prev = s[0];
    int answer = 1;

    for(int i = 1;i<N;i++){
        int rest = L - 1;
        int d = s[i] - prev;
        // cout<<rest<<" "<<d<<"\n";
        if(rest < d){
            prev = s[i];
            answer++;
        }
    }
    cout<<answer;
}