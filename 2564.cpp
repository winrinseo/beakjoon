#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;
int w,h;
int N;
vector<pii> coor;
pii me;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>w>>h>>N;
    for(int i = 0;i<N;i++){
        int a,b;cin>>a>>b;
        coor.push_back({a,b});
    }
    cin>>me.first>>me.second;
    int answer = 0;
    for(int i = 0;i<N;i++){
        int flag = me.first+coor[i].first;
        if(me.first==coor[i].first){//같은 방향인 경우
            answer += abs(me.second-coor[i].second);
        }else if(4<=flag&&flag<=6){//인접한 방향의 경우 방향의 합이 4,5,6
            if(me.first==1){
                if(coor[i].first==3) answer += (me.second+coor[i].second);
                if(coor[i].first==4) answer +=((w-me.second)+coor[i].second);
            }else if(me.first==2){
                if(coor[i].first==3) answer += (me.second+(h-coor[i].second));
                if(coor[i].first==4) answer +=((w-me.second)+(h-coor[i].second));
            }else if(me.first==3){
                if(coor[i].first==1) answer += (me.second+coor[i].second);
                if(coor[i].first==2) answer +=((h-me.second)+coor[i].second);
            }else if(me.first==4){
                if(coor[i].first==1) answer += (me.second+(w-coor[i].second));
                if(coor[i].first==2) answer +=((h-me.second)+(w-coor[i].second));
            }
        }else if(flag==3||flag==7){//반대 방향의 경우 방향의 합이 3 또는 7
            if(me.first==1||me.first==2){
                answer+=min(me.second+h+coor[i].second,
                (w-me.second)+h+(w-coor[i].second));
            }
            if(me.first==3||me.first==4){
                answer+=min(me.second+w+coor[i].second,
                (h-me.second)+w+(h-coor[i].second));
            }
        }  
    }
    cout<<answer;
}