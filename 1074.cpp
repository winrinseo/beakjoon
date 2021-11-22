#include <iostream>
#include <math.h>
using namespace std;
int N,R,C;
int num = 0;
void solve(int r,int c,int size){
    if(size==1){
        if(r==R&&c==C){
            cout<<num;
            exit(0);
        }
        num++;
        return;
    }
    //R,C가 r,c범위 내에 속하지 않는다면 즉시 반환
    if(!((r<=R&&r+size>=R)&&(c<=C&&c+size>=C))){
        num +=(size*size);
        return;
    }
    int mid = size/2;
    solve(r,c,mid);
    solve(r,c+mid,mid);
    solve(r+mid,c,mid);
    solve(r+mid,c+mid,mid);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>R>>C;
    N = pow(2,N);
    solve(0,0,N);
}