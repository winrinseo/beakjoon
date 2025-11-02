#include <iostream>
#include <unordered_set>
using namespace std;
int N,M;
unordered_set<string> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<N;i++){
        string str;

        cin>>str;
        string ss;
        for(int i = 0;i<str.size();i++){
            ss.push_back(str[i]);
            s.insert(ss);
        }
    }

    int answer = 0;
    
    for(int i = 0;i<M;i++){
        string str;
        cin>>str;
        if(s.find(str) != s.end())
            answer++;
    }

    cout<<answer;
}