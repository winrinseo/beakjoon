#include <iostream>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    int answer = 0;

    for(int i = 0;i<N;i++){
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        bool flag = 1;
        if(a[0] == -1 && a[1] == -1 && a[2] == -1){
            flag = 0;
        }
        for(int j = 1;j<3;j++){
            if(a[j-1] == -1 && a[j] >= 0){
                flag = 0;
                break;
            }

            if(!(a[j-1] <= a[j] || (a[j-1] > a[j] && a[j] == -1))){
                flag = 0;
                break;
            }
        }
        answer += flag;
    }
    cout<<answer;
}