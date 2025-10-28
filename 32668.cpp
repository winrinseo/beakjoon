#include <iostream>

using namespace std;

int meet;
string day[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
double d , e , a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>meet;
    meet--;
    cin>>d>>e>>a;
    d/=100; e/=100;a/=100;

    int minus = 1;
    //하루 전부터 시작
    int target = (meet - 1 + 7) % 7;
    double chance = 0.0f;
    while(1){
        //주말
        if(target % 6 == 0){
            //실패 확률 먼저 계산
            chance *= (double)(1.0f - e);
            chance += e;
        }else {
            chance *= (double)(1.0f - d);
            chance += d;
        }
        
        if(chance >= a){
            cout<<"Try to leave on "<<day[target]<<", "<<minus<<" day";
            if(minus > 1) cout<<"s";
            cout<<" before the "<<day[meet]<<" meeting.";
            break;
        }else{
            minus++;
            target -= 1;
            if(target < 0) target+=7;
        }
    }   
}