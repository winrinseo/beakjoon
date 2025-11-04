#include <iostream>
#include <algorithm>
using namespace std;

int N,L;
string name[10005];
int p[10005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>L;

    for(int i = 0;i<N;i++)
        cin>>name[i];

    sort(name , name + N);

    for(int i = 1;i<N;i++){

        for(int j = 0;j<L;j++){
            //몇글자 째에 달라지는지 확인
            if(name[i-1][j] != name[i][j]){
                //저장 글자 개수
                int k = j + 1;
                
                if(p[i-1] < k) p[i-1] = k;
                p[i] = k;
                break;
            }
        }
    }
    int answer = 0;
    for(int i = 0;i<N;i++)
        answer += p[i];

    cout<<answer;
}