#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N,K;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    int p[105];
    //해당 번호가 꽂혀있는지 확인
    bool plug[105] = {0};
    //전기용품의 남은 사용 횟수와 사용 시점을 저장
    pair<int,queue<int>> remain[105];
    vector<int> a;
    for(int i = 0;i<K;i++){
        cin>>p[i];
        remain[p[i]].first++;
        remain[p[i]].second.push(i);
    }
    int res = 0;
    for(int i = 0;i<K;i++){
        //이미 꽃혀있다면
        if(plug[p[i]]){
            remain[p[i]].second.pop();
            remain[p[i]].first--;
            continue;
        }
        if(a.size() < N){
            a.push_back(p[i]);
            plug[p[i]] = true;
            remain[p[i]].second.pop();
            remain[p[i]].first--;
            continue;
        }else{
            //뽑을 콘센트를 선택
            int idx =-1;
            int b = -1;
            for(int j = 0;j<a.size();j++){
                //더 이상 쓰이지 않는다면
                if(remain[a[j]].first==0){
                    idx = j;
                    break;
                }//가장 나중에 쓰일
                if(remain[a[j]].second.front() > b){
                    b = remain[a[j]].second.front();
                    idx = j;
                }
            }
            if(remain[p[i]].first>0){
                remain[p[i]].second.pop();
                remain[p[i]].first--;
            }
            plug[a[idx]] = false;
            a[idx] = p[i];
            plug[p[i]] = true;
            res++;
        }
    }
    std::cout<<res;
}