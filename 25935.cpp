#include <iostream>

using namespace std;

int N;
int d,x,s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;


    while(N--){
        cin>>d>>x>>s;

        int p_lemon = 505 , p_sugar = 505;
        int remain_sugar = 0;
        int answer = 0;
        for(int i = 0;i<d;i++){
            int c , pl , ps;
            cin>>c>>pl>>ps;
            
            p_lemon = min(p_lemon , pl);
            p_sugar = min(p_sugar , ps);

            //레몬부터 계산
            answer += (x * c * p_lemon);

            // 설탕은 필요 온스부터 계산
            int need_s = max(0 , s * c - remain_sugar);
            // 구매해야 할 포대 수
            int buy = need_s / 80;
            if(need_s % 80 != 0) buy++;

            answer += (buy * p_sugar);

            remain_sugar = (buy * 80 + remain_sugar) - (s * c);
        }

        cout<<answer<<"\n";
    }
}