#include <iostream>
using namespace std;
int T,N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        cin>>N;
        string str;
        cin>>str;
        int sign = 1;
        int s_cnt = 0,n_cnt = 0;
        for(int i = 0;i<str.size();i++){
            
            if(sign == 1 && str[i] == '-') {
                sign = -1;
                i++;
            }else if(sign == -1){
                if(i%2 == 0 && str[i] != '0') n_cnt++;
                else s_cnt++;
            }
        }

        
        if(s_cnt && n_cnt){
            cout<<"NO"<<"\n";
        }else cout<<"YES"<<"\n";
    }
}