#include <iostream>

using namespace std;

int N , K;
bool check[20005],s[20005];
string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;

    cin>>str;

    for(int i = 0; i<str.size();i++)
        s[i] = str[i] == 'P';

    for(int i = 0; i<str.size();i++){
        
        for(int j = max(0 , i - K) ; j < i; j++){
            
            //가장 먼저 만나는 반대
            if(s[j] != s[i]){
                
                if(!(check[i] || check[j])){
                    check[i] = check[j] = 1;
                    break;
                }
            }
        }
    }

    int answer = 0;

    for(int i = 0; i<str.size();i++){
        if(s[i] && check[i]) answer++;
    }
    cout<<answer;
}