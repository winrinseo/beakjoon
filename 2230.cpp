#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int p[100005];


long long solve(int k){

    int lo = k + 1 , hi = N - 1;

    while(lo <= hi){
        int mid = (lo + hi) / 2;

        if(p[mid] - p[k] >= M){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return p[lo] - p[k] >= M ? p[lo] - p[k] : 2147483647;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    long long answer = 2147483647;

    for(int i = 0;i<N;i++)
        cin>>p[i];

    sort(p , p + N);

    for(int i = 0;i<N - 1;i++){

        answer = min(answer , solve(i));

    }
    cout<<answer;
}