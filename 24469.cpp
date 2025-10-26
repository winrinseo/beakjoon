#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long p[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++)
        cin>>p[i];

    sort(p,p+N);

    long long answer = 0;
    // 제일 짧은 도로를 가진애한테 다 연결
    // 다른 방법이 있다고 가정하면 두번째로 짧은 도로 + 현재 도로라 더 큰 비용이 소모되서 모순임
    for(int i = 1;i<N;i++){
        answer += (p[0] + p[i]);
    }
    cout<<answer;
}