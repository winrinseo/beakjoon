#include <iostream>

using namespace std;

int N,K;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    string str;
    cin>>str;

    int l = 0 , r = str.size()-1;

    while(K && l < r){

        if(str[r] == 'P'){

            while(l < r && str[l] != 'C') l++;

            if(l < r && str[l] == 'C'){
                K--;
                char temp = str[l];
                str[l] = str[r];
                str[r] = temp;
            }
        }

        r--;
    }

    long long answer = 0;
    long long p_cnt = 0;
    for(int i = 0;i<str.size();i++){
        if(str[i] == 'P') p_cnt++;
        else if(p_cnt >= 2){
            answer += (p_cnt * (p_cnt - 1) / 2);
        }
    }
    cout<<answer;
}