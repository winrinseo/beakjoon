#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    getline(cin,a);
    bool flag = false;
    string ret;
    string rev;
    for(int i = 0;i<a.size();i++){
        if(a[i]=='<'||a[i]=='>'){
            if(!rev.empty()){
                reverse(rev.begin(),rev.end());
                ret+=rev;
                rev.clear();
            }
            ret.push_back(a[i]);
            flag ^= 1;
        }else if(flag){
            ret.push_back(a[i]);
        }else if(a[i]==' '){
            if(!rev.empty()){
                reverse(rev.begin(),rev.end());
                ret+=rev;
                rev.clear();
            }
            ret.push_back(a[i]);
        }else{
            rev.push_back(a[i]);
        }
    }
    if(!rev.empty()){
                reverse(rev.begin(),rev.end());
                ret+=rev;
                rev.clear();
    }
    cout<<ret;
}