#include <iostream>

using namespace std;
int N;
//i번 주사위의 b자리는 눈금 a
int dice[10005][6];
//i번 주사위의 a 눈금은 b번 자리에 있음
int numtoidx[10005][6];
int replect[6] = {5,3,4,1,2,0};
int solve(int depth,int under){
    if(depth==N) return 0;
    //첫주사위
    int ret = 0;
    if(under == -1){
        //아래에 놓일 면
        for(int i = 0;i<6;i++){
            int m = 0;
            for(int j = 6;j>=0;j--){
                if(j==dice[depth][i]||j==dice[depth][replect[i]])
                    continue;
                m = j;break;
            }
            
            ret = max(ret,solve(depth+1,dice[depth][replect[i]])+m);
        }
    }else{
        int m = 0;
        int diff = replect[numtoidx[depth][under]];
        for(int j = 6;j>=0;j--){
            if(j==under||j==dice[depth][diff])
                continue;
            m = j;break;
        }
        ret = solve(depth+1,dice[depth][diff])+m;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<6;j++){
            cin>>dice[i][j];
            numtoidx[i][dice[i][j]] = j;
        }
    }
    cout<<solve(0,-1);
}