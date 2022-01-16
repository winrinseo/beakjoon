#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
using ll = long long;
int N;
pair<int,int> p[200005];
vector<tuple<int,int,int>> rp;
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
    int l = -1,r = -1;
    int dist = 0;
    for(int i = 0;i<N;i++){
        if(r < p[i].first){
            if(l!=-1)
                rp.push_back({l,r,dist});
            l = p[i].first , r = p[i].second;
            dist = r - l;
        }else{
            if(r < p[i].second)
                r = p[i].second;
            dist = r - l;
        }
        if(i==N-1) rp.push_back({l,r,dist});
    }
    //뛸 수 있는 거리 내에서 가장 멀리 뛸 수 있는 판자로 이동
    for(int cur = 0;cur<rp.size();){
        int maxd = get<1>(rp[cur])+get<2>(rp[cur]);
        int md=-1,mx=-1;
        for(int i = cur+1;i<rp.size();i++){
            if(maxd < get<0>(rp[i])) break;
            if(md <= get<1>(rp[i])+get<2>(rp[i])){
                mx = i;
                md = get<1>(rp[i])+get<2>(rp[i]);
            }
        }
        if(mx == -1){
            cout<<get<1>(rp[cur]);
            return 0;
        }else{
            cur = mx;
        }
    }

}