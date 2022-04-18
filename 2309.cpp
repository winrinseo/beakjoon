#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int p[9];
vector<int> s;
void solve(int a,int sum){
    if(s.size()==7){
        if(sum==100){
            sort(s.begin(),s.end());
            for(int i = 0;i<7;i++)
                cout<<s[i]<<"\n";
            exit(0);
        }else
            return;
    }
    for(int i = a+1;i<9;i++){
        s.push_back(p[i]);
        solve(i,sum+p[i]);
        s.pop_back();
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i<9;i++)
        cin>>p[i];
    solve(-1,0);
}