#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
bool cmp(pii& a,pii& b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int N,K;
vector<pii> comp;
multiset<int> attend;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i = 0;i<N;i++){
        int a,b;
        cin>>a>>b;
        comp.push_back({a,b});
    }
    //끝나는 시간을 기준으로 정렬
    sort(comp.begin(),comp.end(),cmp);
    //참가한 대회의 개수 , 마지막으로 참가한 대회의 끝나는 시간(이번 대회에 참여하려면 시작시간이 이 변수보다 커야함)
    int answer = 0,last = 0;
    //최대한 형섭이가 참여하지 못하도록 방해하는 것이 관건임
    for(pii& cur : comp){
        //애초에 참가 못하는 경기
        if(cur.first <= last)
            continue;
        //이전에 참가했던 사람 중 이번 대회에 참여 할 수 있는 가장 빠른 사람을 찾음
        //lower_bound로 찾은 사람은 참가가 불가능 한 사람의 최소 시간을 가지기 때문에 it 앞에 원소가 있다면
        //그 사람이 참여 가능함
        if(!attend.empty()){
            auto it = attend.lower_bound(cur.first);
            if(it != attend.begin()){
                attend.erase(--it);
                attend.insert(cur.second);
                continue;
            }
        }
        //기존 사람을 참가 시킬 수 없다면 참가 시킬 수 있는 다른 사람을 참가시킴
        if(attend.size() < K-1){
            attend.insert(cur.second);
            continue;
        }

        //대회에 참가 가능한 경우, 위 경우들이 모두 불가능 할 경우 반드시 참여가 가능함

        last = cur.second;
        answer++;
        

    }
    cout<<answer;
}