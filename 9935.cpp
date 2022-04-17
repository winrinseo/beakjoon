#include <iostream>
#include <string>
using namespace std;
int dp[1000005];
string a,b;
string st;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;

    for(int i = 0;i<a.size();i++){
        if(st.empty()){
            st.push_back(a[i]);
            if(a[i]==b[0]) dp[0] = 1;
        }else{
            //다음 글자로 이을 수 있는 경우
            if(b[dp[st.size()-1]]==a[i]){
                dp[st.size()] = dp[st.size()-1]+1;
            }else{
                // 중간에 단어가 끊어질 경우
                if(a[i]==b[0])
                    dp[st.size()] = 1;
                else
                    dp[st.size()] = 0;
            }
            st.push_back(a[i]);
        }
        if(dp[st.size()-1]==b.size()){
            for(int k = 0;k<b.size();k++){
                st.pop_back();
                dp[st.size()] = 0;
            }
                
        }
    }
    if(st.empty()) cout<<"FRULA";
    else cout<<st;
}