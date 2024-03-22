#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int p[2000005];
vector<pair<int,int>> origin;
vector<pair<int,int>> aa;
//인덱스 재배치
unordered_map<int , int> idx , idxToOri;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    int cnt = 1;
    for(int i = 0;i<N;i++){
        int s , e;
        cin>>s>>e;
        e--;
        origin.push_back({s , 0});
        origin.push_back({e , 1});
        aa.push_back({s,e});
    }

    sort(origin.begin() , origin.end());

    for(int i = 0;i<origin.size();i++){
        if(idx.find(origin[i].first) == idx.end()){
            //겹치지 않는 구간은 id를 2 올려서 부여
            if(i > 0 && origin[i-1].second == 1 && origin[i].second == 0
            && abs(origin[i - 1].first - origin[i].first) > 1){
                idx[origin[i].first] = cnt+1;
                idxToOri[cnt+1] = origin[i].first;
                cnt+=2;
            }else{
                idx[origin[i].first] = cnt;
                idxToOri[cnt] = origin[i].first;
                cnt++;
            }
        }
    }

    for(int i = 0; i<aa.size();i++){
        p[idx[aa[i].first]] += 1;
        p[idx[aa[i].second] + 1] += -1;
        
    }

    for(int i = 1;i<=cnt; i++){
        p[i] += p[i-1];
    }

    int lo = 0 , hi = 0;
    int ans = - 1, as = -1, ae = -1;

    while(hi <= cnt){
        ++hi;

        if(p[lo] != p[hi]){
            if(ans < p[lo]){
                ans = p[lo];
                as = lo , ae = hi-1;
            }
            lo = hi;
        }
    }
    
    cout<<ans<<"\n"<<idxToOri[as]<<" "<<idxToOri[ae]+1;
}