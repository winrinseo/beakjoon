#include <iostream>

using namespace std;

int N,M;

bool check[2555][2555];

int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
bool m[55][55];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<N;i++){
        string a;
        cin>>a;
        for(int j = 0;j<M;j++){
            m[i][j] = a[j] == '.' ? 0:1;
        }
    }
    int answer = 0;
    int max_hand = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            int a = 0;
            for(int k = 0;k<8;k++){
                int nr = i + d[k][0];
                int nc = j + d[k][1];
                if(nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;
                if(m[i][j] == 0){
                    a += m[nr][nc];
                }else{
                    int myid = i * M + j;
                    int otherid = nr * M + nc;
                    if(check[myid][otherid] || check[otherid][myid])
                        continue;
                    answer += m[nr][nc];

                    check[myid][otherid] = true;
                    check[otherid][myid] = true;
                }
            }

            if(m[i][j] == 0) max_hand = max(max_hand , a);
        }
    }

    cout<<answer + max_hand;
}