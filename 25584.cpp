#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int t[4] = {4,6,4,10};
unordered_map<string,int> duty;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    while(N--){
        for(int i = 0;i<4;i++){
            
            for(int j = 0;j<7;j++){
                string str;
                cin>>str;
                if(str != "-"){
                    duty[str] += t[i];
                }
            }
        }
    }

    vector<int> st;
    for(auto it = duty.begin(); it != duty.end();it++){
        st.push_back(it->second);
    }

    sort(st.begin(),st.end());

    
    if(st.size() == 0 || st[st.size() - 1] - st[0] <= 12)
        cout<<"Yes";
    else cout<<"No";
    
}