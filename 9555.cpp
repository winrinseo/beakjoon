#include <iostream>

using namespace std;
int T;
int N,M;

int m[105][105];

int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;

    while(T--){
        cin>>N>>M;

        for(int i = 1;i<=100;i++)
            for(int j = 1;j<=100;j++)
                m[i][j] = 0;

        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=M;j++){
                cin>>m[i][j];
                if(m[i][j] == -1) m[i][j] = 0;
            }

        bool check[105] = {0};

        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=M;j++){
                if(check[m[i][j]] || m[i][j] == 0)
                    continue;
                for(int k = 0;k<8;k++){
                    if(m[i][j] == m[i+d[k][0]][j+d[k][1]]){
                        check[m[i][j]] = true;
                        break;
                    }
                }
            }
        
        int answer = 0;
        for(int i = 1;i<=100;i++)
            answer += check[i];
        
        cout<<answer<<'\n';
    }
}