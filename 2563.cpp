#include <iostream>
using namespace std;

int N;
bool board[105][105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int t = 0;t<N;t++){
        int a,b;cin>>a>>b;
        for(int i = b;i<b+10;i++){
            for(int j = a;j<a+10;j++){
                board[i][j] = 1;
            }
        }
    }
    int answer = 0;
    for(int i = 0;i<105;i++)
        for(int j = 0;j<105;j++)
            answer+=board[i][j];
    cout<<answer;
}  