#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


struct Vector2{
    double x , y;

    Vector2 operator-(Vector2 b){
        return {this->x-b.x , this->y-b.y};
    }
};


vector<int> stat;
int st[8];
bool sel[8];

int solve(){
    if(stat.size()==8){
        int ret = 1;

        for(int i = 0;i<8;i++){
            int left = (i+1)%8;
            int right = (i+2)%8;

            // 각 스텟을 0,stat으로 가정하고 각각 0, 45, 90도 회전한 좌표
            Vector2 first = {0,stat[i]}; 
            Vector2 second = {-stat[left] * sqrt(2) / 2,stat[left] * sqrt(2) / 2};
            Vector2 third = {-stat[right] , 0};

            // 벡터 생성
            Vector2 a = first - second;
            Vector2 b = third - second;

            // 외적 판별식 A X B;
            double crossProduct = a.x * b.y - a.y * b.x;
            
            // crossProduct > 0 : ccw , crossProduct < 0 : cw , crossProduct == 0 : 평행
            if(crossProduct >= 0){
                ret = 0;
                break;
            }
        }
        return ret;
    }
    int ret = 0;
    for(int i = 0;i<8;i++){
        if(!sel[i]){
            sel[i] = true;
            stat.push_back(st[i]);
            ret += solve();
            stat.pop_back();
            sel[i] = false;
        }
    }

    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0;i<8;i++){
        cin>>st[i];
    }

    cout<<solve();
}