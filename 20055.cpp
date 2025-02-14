#include <iostream>
#include <queue>

using namespace std;

int N,K;
int con[205];
bool check[205];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;
    int n = N*2;

    for(int i = 0;i<n;i++)
        cin>>con[i];
    
    int ans = 0;
    int on = 0;
    int down = N-1;
    while(K > 0){
        ans++;
        //한칸 회전 (초기 위치만 기록)
        on = on - 1 < 0 ? n - 1 : on - 1; //올리는 위치의 idx
        down = down - 1 < 0 ? n - 1 : down - 1;
        int aa = q.size();
        for(int i = 0;i<aa;i++){
            if(q.front() == down){
                q.pop();
                check[down] = false;
                break;
            }
            q.push(q.front());
            q.pop();
        }
        //로봇 이동
        aa = q.size();
        for(int i = 0;i<aa;i++){
            int next = (q.front() + 1) % n; 

            if(!check[next] && con[next]){
                check[q.front()] = false;
                if(!(--con[next])) K--;
                if(next != down) {
                    q.push(next);
                    check[next] = true;
                }
                q.pop();
            }else{
                q.push(q.front());
                q.pop();
            }
        }

        //로봇 생성
        if(!check[on] && con[on]){
            check[on] = true;
            if(!(--con[on])) K--;
            q.push(on);
        }

        
    }
    cout<<ans;
}