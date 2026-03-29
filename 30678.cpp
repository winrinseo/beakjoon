#include <iostream>
#include <cmath>
using namespace std;


int N;
bool map[5000][5000];

void star(int level, int r, int c){
    if(level == 0) {
        map[r][c] = 1;
        return;
    }

    int cell = pow(5,level-1);


    //1행
    star(level - 1 , r , c + cell * 2);
    //2행
    star(level - 1 , r + cell * 1, c + cell * 2);
    //3행
    star(level - 1 , r + cell * 2, c + cell * 0);
    star(level - 1 , r + cell * 2, c + cell * 1);
    star(level - 1 , r + cell * 2, c + cell * 2);
    star(level - 1 , r + cell * 2, c + cell * 3);
    star(level - 1 , r + cell * 2, c + cell * 4);
    //4행
    star(level - 1 , r + cell * 3, c + cell * 1);
    star(level - 1 , r + cell * 3, c + cell * 2);
    star(level - 1 , r + cell * 3, c + cell * 3);
    //5행
    star(level - 1 , r + cell * 4, c + cell * 1);
    star(level - 1 , r + cell * 4, c + cell * 3);



    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    star(N,0,0);
    
    int n = pow(5 ,N);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(map[i][j]) cout<<'*';
            else cout<<' ';
        }
        cout<<"\n";
    }
}