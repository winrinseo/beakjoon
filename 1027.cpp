#include <iostream>
#define pii pair<long long,long long>

using namespace std;

int ccw(pii a , pii b , pii c){
    //ab,ac 외적
    long long z = (b.first - a.first) * (c.second - a.second) - 
                        (b.second-a.second) * (c.first - a.first);

    if(z > 0) return 1;
    if(z == 0) return 0;
    if(z < 0) return -1;
}


bool cross(pair<pii , pii> l1 , pair<pii,pii> l2){
    pii a = l1.first;
    pii b = l1.second;
    pii c = l2.first;
    pii d = l2.second;

    //겹치기 위해선 한 선분과 다른 선분의 각 점이 시계 , 반시계 방향이 나와야댐
    int ab = ccw(a , b , c) * ccw(a , b , d);
    int cd = ccw(c , d , a) * ccw(c , d , b);

    //두 선분이 일직선인 경우
    if(ab == 0 && cd == 0){
        if(a > b) swap(a , b);
        if(c > d) swap(c , d);
        //두 선분이 포개어있는지 확인
        return c <= b && a <= d;
    }

    return ab <= 0 && cd <= 0;
}

int N;

long long arr[55];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++)
        cin>>arr[i];


    int ans = 0;

    for(int i = 0;i<N;i++){
        int cnt = 0;
        for(int j = 0;j<N;j++){
            if(i == j) continue;
            int from = i;
            int to = j;
            if(from > to) swap(from , to);

            pair<pii,pii> l1 = {{from , arr[from]} , {to , arr[to]}};
            bool flag = true;
            for(int z = from + 1; z < to; z++){
                pair<pii,pii> l2 = {{z , 0} , {z , arr[z]}};
                
                //두 선분이 교차 한다면

                if(cross(l1 , l2)){
                    flag = false;
                    break;
                }
            }
            cnt += flag;
        }
        ans = max(ans , cnt);
    }
    cout<<ans;
}