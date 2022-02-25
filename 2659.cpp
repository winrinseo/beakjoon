#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string aaa(4,' ');
vector<int> a;
int isvalid(int x){
    int t = x;
    for(int i = 0;i<3;i++){
        x = x % 1000 * 10 + x / 1000;
        t = min(t,x);
    }
    
    return t;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i<4;i++)
        cin>>aaa[i];
    
    for(int i = 0;i<4;i++){
        string s;
        for(int j = i;j<i+4;j++){
            s.push_back(aaa[j%4]);
        }
        a.push_back(stoi(s));
    }

    sort(a.begin(),a.end());
    int cnt = 0;
    for(int i = 1111;i<=a[0];i++){
        if(isvalid(i)==i) cnt++;
    }
    cout<<cnt;
}