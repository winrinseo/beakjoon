#include <iostream>
#include <algorithm>
using namespace std;
char board[205][205];
int N,M;
int d[4][2] = {{0,1},{1,1},{1,0},{1,-1}};
int check(string a){
    int ret = 0;
    if(a.size()!=4) return 0;
    for(int k = 0;k<2;k++){
        int score = 0;
        for(int i = 0;i<a.size();i++){
            if(i==0&&(a[i]=='E'||a[i]=='I')) score++;
            if(i==1&&(a[i]=='N'||a[i]=='S')) score++;
            if(i==2&&(a[i]=='F'||a[i]=='T')) score++;
            if(i==3&&(a[i]=='P'||a[i]=='J')) score++;

        }
        if(score==4) ret++;
        reverse(a.begin(),a.end());
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 0;i<N;i++)
        for(int j = 0;j<M;j++)
            cin>>board[i][j];
    int answer = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            for(int k = 0;k<4;k++){
                string a;
                int y = i,x = j;
                for(int s = 0;s<4;s++){
                    a.push_back(board[y][x]);
                    y+=d[k][0]; x+=d[k][1];
                    if(y>=N||x>=M||y<0||x<0) break;
                }
                answer+=check(a);
            }
        }
    }
       
    cout<<answer; 
}