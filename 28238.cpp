#include <iostream>

using namespace std;

int N;
int p[5][5];
int want[5];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    int answer = 0;

    for(int k = 0;k<N;k++){
        for(int i = 0;i<5;i++)
            cin>>want[i];

        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){
                if(i == j) continue;
                if(want[i] == 1 && want[j] == 1){
                    p[i][j]++;
                    answer = max(answer , p[i][j]);
                }
            }
        }
    }

    cout<<answer<<"\n";

    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(i == j) continue;
            if(answer == p[i][j]){
                for(int k = 0;k<5;k++){
                    if(k == i || k == j)
                        cout<<"1 ";
                    else cout<<"0 ";
                }
                return 0;
            }
        }
    }  
}