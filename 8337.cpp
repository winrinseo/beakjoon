/*
바이트맨은 한 변이 1인 n개의 정사각형을 가지고 있다.
이 사각형들을 이용해서 얼마나 많은 다른 직사각형을 만들수 있을까?
두 직사각형중에 하나를 회전시키거나 이동시켜 두번째 직사각형을 얻을 수 없다면 두 사각형은 서로 다른 것으로 취급된다.
(1 * 4 직사각형과 4 * 1 직사각형은 같은 것으로 취급)
직사각형을 만드는 동안 바이트맨은 사각형을 변형시키거나 다른 정사각형위에 어떤 정사각형을 올려놓지 못한다.

입력
표준 입력으로 구성된 하나의 정수 n이 입력된다. (1 <= n <= 1,000,000,000)

출력
바이트맨이 가진 정사각형으로 만들 수 있는 서로 다른 직사각형의 수 하나를 출력한다..
*/


#include <iostream>
using namespace std;

long long N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    long long answer = N;
    //높이 r
    for(int i = 2;i<=N;i++){
        //만들 수 있는 가로의 크기
        long long width = N / i;
        if( i > width) break;
        answer += (width - (i - 1));
    }
    
    cout<<answer;
}