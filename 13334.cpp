#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N;
pair<int,int> coor[100005];
struct cmp{
    bool operator()(int& a,int& b){
        return a > b;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    priority_queue<int,vector<int>,cmp> pq;
    for(int i = 0;i<N;i++){
        cin>>coor[i].first>>coor[i].second;
        if(coor[i].first>coor[i].second)
            swap(coor[i].first,coor[i].second);
    }
    int dist; cin>>dist;
    int answer = 0;
    //선분의 오른쪽을 기준으로 정렬
    sort(coor,coor+N,[](pair<int,int>& a,pair<int,int>& b){
        if(a.second==b.second) return a.first < b.first;
        return a.second < b.second;
    });
    //철로의 위치는 이번에 들어갈 선분의 끝점을 기준으로 선정
    for(int i = 0;i < N;i++){
        if(coor[i].second-coor[i].first <= dist){
            if(pq.empty()) pq.push(coor[i].first);
            else{
                //이번 철로의 위치에 들어갈 수 없는 선분들은 모두 pop
                while(coor[i].second-dist > pq.top()){
                    pq.pop();
                    if(pq.empty()) break;
                }
                pq.push(coor[i].first);
                answer = max(answer,(int)pq.size());
            }
        }
    }
    std::cout<<answer;
}