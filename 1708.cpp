#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#define ll long long
using namespace std;
struct Point{
    ll x,y;
};
ll N;
Point p[100005];
ll ccw(Point& a,Point& b,Point& c){
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++)
        cin>>p[i].x>>p[i].y;
    
    //y좌표 기준으로 정렬
    sort(p,p+N,[](Point& a,Point& b){
        if(a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    //나머진 원점을 기준으로 반시계방향으로 정렬

    sort(p+1,p+N,[](Point& a,Point& b){
        ll ret = ccw(p[0],a,b);
        if(ret > 0){ //반시계 방향일 경우
            return true;
        }else if(ret < 0){ // 시계 방향일 경우
            return false;
        }else{//거리 기준
            //return a.x + a.y < b.x + b.y;
            if (a.y == b.y) return a.x < b.x;
		    return a.y < b.y;
        }
    });
    stack<int> s;
    s.push(0);
    s.push(1);
    
    for(int next = 2;next<N;next++){
        
        while(s.size() >= 2){
            //first -> second
            int second = s.top();
            s.pop();
            int first = s.top();
            //ccw가 반시계 방향이 나올 때 까지 반복
            if(ccw(p[first],p[second],p[next]) > 0){
                s.push(second);//유효하니까 다시 넣어줌
                break;
            }
        }


        s.push(next);
    }
    cout<<s.size();
}