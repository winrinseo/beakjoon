#include <iostream>

using namespace std;
string x,y;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>x>>y;
    int gap = y.size()-x.size();
    int answer = 100;
    for(int k = gap;k>=0;k--){
        int score = 0;
        for(int i = k;i<k+x.size();i++){
            if(y[i]!=x[i-k]) score++;
        }
        answer = min(answer,score);
    }
    cout<<answer;
}