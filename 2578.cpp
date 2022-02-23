#include <iostream>
#define M 5
using namespace std;
//row,col
pair<int,int> pos[26];
int row[5],col[5],dig[2],cmd[26];
int m = (1<<M)-1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            int a;cin>>a;
            pos[a] = {i,j};
        }
    }
    for(int i = 1;i<=25;i++)
        cin>>cmd[i];
    for(int c = 1;c<=25;c++){
        int i = pos[cmd[c]].first;
        int j = pos[cmd[c]].second;
        row[i] |= (1<<j);
        col[j] |= (1<<i);
        if(i==j) dig[0] |= (1<<i);
        if(i+j==4) dig[1] |= (1<<i);
        int cnt = 0;
        for(int z = 0;z<5;z++)
            if(row[z]==m) cnt++;
        for(int z = 0;z<5;z++)
            if(col[z]==m) cnt++;
        for(int z = 0;z<2;z++)
            if(dig[z]==m) cnt++;
        if(cnt>=3){
            cout<<c;
            return 0;
        }
    }
}