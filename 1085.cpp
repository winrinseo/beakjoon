#include <iostream>
#include <algorithm>
using namespace std;
int x,y,w,h;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>x>>y>>w>>h;
    int answer = min(x,y);
    answer = min(answer,min(w-x,h-y));
    cout<<answer;
}