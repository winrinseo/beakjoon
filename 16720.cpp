#include <iostream>
#include <queue>
using namespace std;


int N;
int zidx[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 1;i<N-1;i++){
        string str;cin>>str;
        for(int j = 0;j<4;j++)
            if(str[j] == '0'){
                zidx[i] = j;
                break;
            }
    }

    int answer = 987654321;
    //시작 지점
    for(int k = 0;k<4;k++){
        
        int dist = k;

        for(int i = 1;i<N-1;i++){
            //오른쪽, 왼쪽 비교
            if(k < zidx[i]){ // 길이 오른쪽에 있을때
                dist += min(zidx[i] - k , k + 4 - zidx[i]);
            }else if(k > zidx[i]){
                dist += min(k - zidx[i] , zidx[i] - (k - 4));
            }
            dist += 1;
        }
        //한칸 더 내리기
        dist++;
        dist += (3-k);
        answer = min(answer , dist);
    }
    cout<<answer;
}