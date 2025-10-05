#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;

vector<int> split(string str){
    vector<int> ret;
    string s;

    for(int i = 0;i<str.size();i++){
        if(str[i] == ':'){
            ret.push_back(stoi(s));
            s.clear();
        }else{
            s.push_back(str[i]);
        }
    }
    if(!s.empty()) ret.push_back(stoi(s));

    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;


    while(N--){
        string str;
        cin>>str;
        
        vector<int> t = split(str);
        
        for(int i = 5;i>=0;i--){
            for(int j = 0;j<3;j++){
                if((t[j] & (1<<i)) != 0){
                    cout<<1;
                }else cout<<0;
            }
        }
        cout<<" ";

        for(int i = 0;i<3;i++){
            for(int j = 5;j>=0;j--){
                if((t[i] & (1<<j)) != 0){
                    cout<<1;
                }else cout<<0;
            }
        }

        cout<<"\n";
    }
}