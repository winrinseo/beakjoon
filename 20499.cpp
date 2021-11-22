#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    vector<int> aa;
    string b;
    for(int i = 0;i<a.size();i++){
        if(a[i]=='/'){
            aa.push_back(stoi(b));
            b.clear();
        }else{
            b.push_back(a[i]);
            if(i==a.size()-1){
                aa.push_back(stoi(b));
            }
        }
    }
    if(aa[0]+aa[2] < aa[1]||aa[1]==0) cout<<"hasu";
    else cout<<"gosu";
}