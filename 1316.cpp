#include <iostream>
#include <string>
using namespace std;
int N;
string word;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int answer = 0;
    for(int i =0;i<N;i++){
        bool used[26]={0};
        word.clear();
        cin>>word;
        int prev = word[0]-'a';
        bool flag = true;
        for(int w = 1;w<word.size();w++){
            if(used[word[w]-'a']){
                flag = false;
                break;
            }
            if(prev!=(word[w]-'a')){
                used[prev] = true;
                prev = word[w]-'a';
            }
        }
        if(flag) answer++;
    }
    cout<<answer;
}
