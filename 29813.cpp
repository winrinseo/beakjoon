#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int N;
queue<string> q;
unordered_map<string,int> num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>N;

    for(int i = 0;i<N;i++){
        string s;int a;cin>>s>>a;
        num[s] = a;
        q.push(s);
    }
    while(q.size()>1){
        string cur = q.front();q.pop();

        int c = num[cur] - 1;

        c %= q.size();

        for(int i = 0;i<c;i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    cout<<q.front();
    
}