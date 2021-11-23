#include <iostream>
#include <string>
using namespace std;
string c = "driip";
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    int idx = 0;
    for(int i = 0;i<a.size();i++){
        if(c[idx]!=a[i]){
            idx = 0;
        }else{
            idx++;

        }
        if(idx==c.size()&&i==a.size()-1){
            idx = -1;
            cout<<"cute";
            break;
        }else if(idx==c.size()&&i!=a.size()-1){
            idx = 0;
        }
    }
    if(idx!=-1)
        cout<<"not cute";
}