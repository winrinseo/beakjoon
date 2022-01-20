#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define INF -1000000005
using namespace std;
using ll = long long;
int N;
pair<int,int> p[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>p[i].first>>p[i].second;
    }
    //오른쪽 좌표를 기준으로 정렬
    sort(p,p+N);
    //선분 병합.
    int l = INF,r = INF;
    ll result = 0;
    for(int i = 0;i<N;i++){
        if(r < p[i].first){
            result += (r - l);
            l = p[i].first , r = p[i].second;
        }else{
            if(r < p[i].second)
                r = p[i].second;
        }
    }
    result += (r - l);
    cout<<result;
}